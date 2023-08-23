package com.sw;

import java.util.Scanner;

public class p1954 {
    static int n;
    static int t;
    static int arr[][];

    static int Count;

    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            n = sc.nextInt();
            arr = new int[n][n];
            Count = 1;
            System.out.println("#" + i);
            move(0, 0, 0);

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    System.out.print(arr[j][k] + " ");
                }
                System.out.println();
            }
        }
    }

    // dir = 1 오른쪽, 2 아래, 3 왼쪽, 4 위
    static void move(int x, int y, int dir) {
        if (Count == n * n) {
            arr[x][y] = Count;
            return;
        }
        arr[x][y] = Count;
        Count++;

        int next_x = x + dx[dir];
        int next_y = y + dy[dir];

        // 벽을 만나는 경우
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) {
            dir = (dir+1) % 4;
        }
        else if (arr[next_x][next_y] != 0) {
            dir = (dir+1) % 4;
        }

        move(x + dx[dir], y + dy[dir], dir);
    }
}
