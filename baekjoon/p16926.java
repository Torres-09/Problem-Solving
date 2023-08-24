package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p16926 {
    static int n, m, r;
    static int arr[][] = new int[301][301];

    static void rotate(int x, int y, int xLast, int yLast) {
        int temp1 = arr[x][y];
        int temp2 = arr[xLast][y];
        int temp3 = arr[xLast][yLast];
        int temp4 = arr[x][yLast];
        int temp;
        // 아래
        for (int i = x+1; i <= xLast; i++) {
            // 아래로
            temp = arr[i][y];
            arr[i][y] = temp1;
            temp1 = temp;
        }
        // 오른쪽으로
        for (int i = y+1; i <= yLast; i++) {
            temp = arr[xLast][i];
            arr[xLast][i] = temp2;
            temp2 = temp;
        }
        // 위로
        for (int i = xLast -1; i >= x; i--) {
            temp = arr[i][yLast];
            arr[i][yLast] = temp3;
            temp3 = temp;
        }
        // 왼쪽으로
        for (int i = yLast -1; i >= y; i--) {
            temp = arr[x][i];
            arr[x][i] = temp4;
            temp4 = temp;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                arr[i][j] = Integer.parseInt(st2.nextToken());
            }
        }
        for (int a = 0; a < r; a++) {
            for (int i = 1; i<= Math.min(n,m) / 2; i++) {
                rotate(i, i, n - i + 1, m - i + 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
