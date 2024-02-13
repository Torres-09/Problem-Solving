package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1149 {
    static int N;
    static int[][] dp;
    static int[] red, green, blue;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new int[N + 1][3];
        red = new int[N + 1];
        green = new int[N + 1];
        blue = new int[N + 1];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            red[i] = Integer.parseInt(st.nextToken());
            green[i] = Integer.parseInt(st.nextToken());
            blue[i] = Integer.parseInt(st.nextToken());
        }

        dp[0][0] = red[0];
        dp[0][1] = green[0];
        dp[0][2] = blue[0];

        for (int i = 1; i < N; i++) {
            dp[i][0] += Math.min(dp[i - 1][1], dp[i - 1][2]) + red[i];
            dp[i][1] += Math.min(dp[i - 1][0], dp[i - 1][2]) + green[i];
            dp[i][2] += Math.min(dp[i - 1][0], dp[i - 1][1]) + blue[i];
        }

        System.out.println(Math.min(dp[N - 1][0], Math.min(dp[N - 1][1], dp[N - 1][2])));
    }
}
