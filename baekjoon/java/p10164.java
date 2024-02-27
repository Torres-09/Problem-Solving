package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p10164 {
    static int N, M, K;
    static int a, b;
    static int num;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dp = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                num++;
                if (num == K) {
                    a = i;
                    b = j;
                }
            }
        }

        if (K != 0) {
            for (int i = 0; i <= a; i++) {
                dp[i][0] = 1;
            }
            for (int i = 0; i <= b; i++) {
                dp[0][i] = 1;
            }

            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }

            for (int i = a; i < N; i++) {
                dp[i][b] = dp[a][b];
            }
            for (int i = b; i < M; i++) {
                dp[a][i] = dp[a][b];
            }

            for (int i = a; i < N; i++) {
                for (int j = b; j < M; j++) {
                    if (i - 1 < 0 || j - 1 < 0) continue;
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                dp[i][0] = 1;
            }
            for (int i = 0; i < M; i++) {
                dp[0][i] = 1;
            }

            for (int i = 1; i < N; i++) {
                for (int j = 1; j < M; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        System.out.println(dp[N - 1][M - 1]);
    }
}
