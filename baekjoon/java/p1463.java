package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1463 {
    static int N;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new int[1000003];
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for (int i = 4; i <= N; i++) {
            dp[i] = dp[i-1] + 1;
            if (i % 3 == 0) dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
            if (i % 2 == 0) dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
        }
        System.out.println(dp[N]);
    }
}
