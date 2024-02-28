package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p16395 {
    static int[][] dp;
    static int N, K;
    public static void main(String[] args) throws IOException {
        dp = new int[31][31];
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= 30; i++) {
            dp[i][0] = 1;
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
            dp[i][i] = 1;
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        System.out.println(dp[N - 1][K - 1]);
    }
}
