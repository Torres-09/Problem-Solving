package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class p2186 {
	static int N, M, K;
	static char[][] graph;
	static String comp;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static int answer;
	static int[][][] visit;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		graph = new char[N][M];
		visit = new int[N][M][81];

		Queue<int[]> q = new ArrayDeque<>();
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < M; j++) {
				graph[i][j] = s.charAt(j);
				q.add(new int[] {i, j, 0});
			}
		}

		comp = br.readLine();

		while (!q.isEmpty()) {
			int x = q.peek()[0];
			int y = q.peek()[1];
			int z = q.peek()[2];
			q.poll();

			if (z == 0) {
				if (graph[x][y] != comp.charAt(0)) {
					continue;
				} else {
					visit[x][y][0]++;
				}
			}

			for (int i = 0; i < 4; i++) {
				for (int j = 1; j <= K; j++) {
					int nextX = x + dx[i] * j;
					int nextY = y + dy[i] * j;

					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
					if(z + 1 == comp.length()) continue;
					if (graph[nextX][nextY] != comp.charAt(z + 1)) continue;
					if (visit[nextX][nextY][z + 1] != 0) {
						visit[nextX][nextY][z+1] += visit[x][y][z];
						continue;
					}
					visit[nextX][nextY][z+1] += visit[x][y][z];
					q.add(new int[] {nextX, nextY, z + 1});
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == comp.charAt(comp.length() - 1)) {
					answer += visit[i][j][comp.length() - 1];
				}
			}
		}

		System.out.println(answer);
	}
}
