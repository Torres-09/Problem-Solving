package com.baekjoon.java;

import java.util.Scanner;

public class p11660 {
    static int[][] num;
    static int[][] dp;
    static int n, m;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        num = new int[1025][1025];
        dp = new int[1025][1025];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                num[i][j] = scanner.nextInt();
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j] + num[i][j] - dp[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();
            System.out.println(dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
        }
    }
}
