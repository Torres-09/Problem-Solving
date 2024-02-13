package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1600 {
    static int n;
    static int[][] board;

    // 가로 세로 대각선

    static int[][][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        board = new int[n + 1][n + 1];
        dp = new int[n + 1][n + 1][3];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // x, y, 방향
        dp[1][1][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 벽이면 올 수 없다.
                if (board[i][j] == 1) continue;
                if (i == 1 && j == 1) continue;

                // 가로로 놓여있는 파이프
                if (j + 1 <= n) {
                    if (board[i][j + 1] == 0) {
                        if (board[i][j - 1] == 0) dp[i][j][0] += dp[i][j - 1][0];
                        if (board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1] == 0)
                            dp[i][j][0] += dp[i - 1][j - 1][2];
                    }
                }

                // 세로로 놓여있는 파이프
                if (i + 1 <= n) {
                    if (board[i + 1][j] == 0) {
                        if (board[i - 1][j] == 0) dp[i][j][1] += dp[i - 1][j][1];
                        if (board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1] == 0)
                            dp[i][j][1] += dp[i - 1][j - 1][2];
                    }
                }

                // 대각선으로 놓여있는 파이프
                if (i + 1 <= n && j + 1 <= n) {
                    if (board[i + 1][j + 1] + board[i][j + 1] + board[i + 1][j] == 0) {
                        if (board[i][j - 1] == 0) dp[i][j][2] += dp[i][j - 1][0];
                        if (board[i - 1][j] == 0) dp[i][j][2] += dp[i - 1][j][1];
                        if (board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1] == 0)
                            dp[i][j][2] += dp[i - 1][j - 1][2];
                    }
                }
            }
        }

        System.out.println(dp[n][n - 1][0] + dp[n - 1][n][1] + dp[n - 1][n - 1][2]);
    }
}
