package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p2448 {
	static int N;

	static String[] map;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
		N = Integer.parseInt(stringTokenizer.nextToken());
		map = new String[N];

		map[0] = "  *  ";
		map[1] = " * * ";
		map[2] = "*****";

		for (int i = 1; 3 * (int)Math.pow(2, i) <= N; i++) {
			solve(i);
		}

		for (String s : map) {
			System.out.println(s);
		}
	}

	static void solve(int k) {
		int bottom = 3 * (int)Math.pow(2, k);
		int middle = bottom / 2;
		for (int i = middle; i < bottom; i++) {
			map[i] = map[i - middle] + " " + map[i - middle];
		}
		StringBuilder space = new StringBuilder();
		while (space.length() < middle) {
			space.append(" ");
		}
		for (int i = 0; i < middle; i++) {
			map[i] = space + map[i] + space;
		}
	}
}
