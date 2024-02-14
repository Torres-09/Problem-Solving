package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class p2407 {
	static BigInteger[][] dp = new BigInteger[101][101];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < 101; i++) {
			dp[i][0] = BigInteger.ONE;
			for (int j = 1; j < i; j++) {
				dp[i][j] = dp[i - 1][j].add(dp[i - 1][j - 1]);
			}
			dp[i][i] = BigInteger.ONE;
		}

		System.out.println(dp[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())]);
	}
}
