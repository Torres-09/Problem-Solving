package com.sw;

import java.util.Scanner;

public class p1210 {
    static int arr[][] = new int[101][101];
    static int t;
    static int index;
    static boolean flag;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = 10;
        while (t > 0) {
            index = sc.nextInt();
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            int answer = 0;
            for (int i = 0; i < 100; i++) {
                flag = false;
                if (arr[0][i] == 1) Move(0, i, 0);

                if (flag == true) {
                    answer = i;
                    break;
                }
            }

            t--;
            System.out.println("#" + index + " " + answer);
        }
    }

    static void Move(int x, int y, int LeftRight) {
        if (x == 99) {
            if (arr[x][y] == 2) {
                flag = true;
            }
            return;
        }

        boolean left = false;
        boolean right = false;
        if (y - 1 >= 0) left = true;
        if (y + 1 < 100) right = true;

        // 왼쪽 ( 1-> 왼쪽으로 이동 중, 0 -> 아래로 이동 중
        if (left && arr[x][y - 1] == 1 && (LeftRight == 1 || LeftRight == 0)) {
            Move(x, y - 1, 1);
        }
        // 오른쪽
        else if (right & arr[x][y + 1] == 1 & (LeftRight == 2 || LeftRight == 0)) {
            Move(x, y + 1, 2);
        } else
            // 아래로 이동
            Move(x + 1, y, 0);
    }
}
