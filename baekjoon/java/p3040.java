package com.baekjoon.java;

import java.util.Scanner;

public class p3040 {
    static int arr[] = new int[9];
    static boolean[] isSelected = new boolean[9];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 9; i++) {
            arr[i] = sc.nextInt();
        }

        combination(0, 0);
    }

    static void combination(int start, int cnt) {
        if (cnt == 7) {
            int temp = 0;
            for (int i = 0; i < 9; i++) {
                if (isSelected[i]) temp += arr[i];
            }

            if (temp == 100) {
                for (int i = 0; i < 9; i++) {
                    if (isSelected[i]) System.out.println(arr[i]);
                }
            }

            return;
        }

        for (int i = start; i < 9; i++) {
            isSelected[i] = true;
            combination(i + 1, cnt + 1);
            isSelected[i] = false;
        }
    }
}
