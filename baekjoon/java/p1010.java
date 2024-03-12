package com.baekjoon.java;

import java.util.*;
import java.io.*;

public class p1010 {
    static int t, n, m;
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        t = Integer.parseInt(br.readLine());
        dp = new long[31][31];

        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;

        for (int i = 2; i <= 30; i++) {
            dp[i][0] = 1;
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            dp[i][i] = 1;
        }

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            System.out.println(dp[m][n]);
        }
    }
}
