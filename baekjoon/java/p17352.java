package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p17352 {
	static int N;
	static int[] arr;

	static int find(int c) {
		if (c == arr[c])
			return c;
		else
			return arr[c] = find(arr[c]);
	}

	static void union(int a, int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		arr[aRoot] = bRoot;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			arr[i] = i;
		}

		for (int i = 0; i < N - 2; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			union(a, b);
		}

		for (int i = 1; i < N; i++) {
			if (find(i) != find(i + 1)) {
				System.out.println(i + " " + (i + 1));
				break;
			}
		}
	}
}
