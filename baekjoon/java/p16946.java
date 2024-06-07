package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;
import java.util.StringTokenizer;

public class p16946 {
	// 0 이동가능 1 이동불가능 벽
	static int[][] graph;
	static int N, M;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static int[][] group;
	static HashMap<Integer, Integer> groupMap = new HashMap<>();
	static int groupId = 1;
	static boolean visitGroup[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		graph = new int[N][M];
		group = new int[N][M];
		for (int i = 0; i < N; i++) {
			String line = br.readLine();
			for (int j = 0; j < M; j++) {
				graph[i][j] = line.charAt(j) - '0';
			}
		}

		boolean[][] visit = new boolean[N][M];

		// 모든 칸에서 BFS를 실시
		// 빈 칸에서 이동 가능한 칸을 모두 적어준다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(graph[i][j] == 1) continue;
				if(visit[i][j]) continue;

				Queue<int[]> q = new ArrayDeque<>();
				q.add(new int[] {i, j});
				visit[i][j] = true;
				group[i][j] = groupId;
				int cnt = 1;

				while (!q.isEmpty()) {
					int x = q.peek()[0];
					int y = q.peek()[1];
					q.poll();

					for (int k = 0; k < 4; k++) {
						int nextX = x + dx[k];
						int nextY = y + dy[k];

						if(nextX< 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
						if(graph[nextX][nextY] == 1) continue;
						if(visit[nextX][nextY]) continue;

						visit[nextX][nextY] = true;
						cnt++;
						group[nextX][nextY] = groupId;
						q.add(new int[] {nextX, nextY});
					}
				}

				groupMap.put(groupId++, cnt);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 1) {
					int cnt = 1;
					visitGroup = new boolean[groupId];
					for (int k = 0; k < 4; k++) {
						int nextX = i + dx[k];
						int nextY = j + dy[k];
						if(nextX< 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
						if(graph[nextX][nextY] != 0) continue;
						if(visitGroup[group[nextX][nextY]]) continue;

						visitGroup[group[nextX][nextY]] = true;
						cnt += groupMap.get(group[nextX][nextY]);
					}
					graph[i][j] = cnt;
				}
			}
		}

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(graph[i][j] % 10);
			}
			sb.append("\n");
		}

		System.out.print(sb);
	}
}
