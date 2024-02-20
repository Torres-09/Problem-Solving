package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p1043 {
	static int N, M;
	static boolean[] knows;
	static int[] parents;
	static int answer;
	static ArrayList<Integer>[] party;

	static int find(int c) {
		if (c == parents[c]) {
			return c;
		}
		return parents[c] = find(parents[c]);
	}

	static void union(int a, int b) {
		int aRoot = find(Math.max(a, b));
		int bRoot = find(Math.min(a, b));

		if (aRoot == bRoot)
			return;

		if (knows[aRoot] || knows[bRoot]) {
			knows[aRoot] = true;
			knows[bRoot] = true;
		}

		parents[aRoot] = bRoot;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());

		knows = new boolean[N + 1];
		parents = new int[N + 1];
		party = new ArrayList[M + 1];
		answer = M;

		for (int i = 0; i <= M; i++) {
			party[i] = new ArrayList<>();
		}
		for (int i = 0; i <= N; i++) {
			parents[i] = i;
		}

		int know = Integer.parseInt(st.nextToken());
		for (int i = 0; i < know; i++) {
			knows[Integer.parseInt(st.nextToken())] = true;
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int participants = Integer.parseInt(st.nextToken());
			int first = Integer.parseInt(st.nextToken());
			party[i].add(first);

			for (int j = 0; j < participants - 1; j++) {
				int next = Integer.parseInt(st.nextToken());
				party[i].add(next);
				union(first, next);
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < party[i].size(); j++) {
				if (knows[party[i].get(j)] || knows[find(party[i].get(j))]) {
					answer--;
					break;
				}
			}
		}

		System.out.println(answer);
	}
}

// https://www.acmicpc.net/problem/1043