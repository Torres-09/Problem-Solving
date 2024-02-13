package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Queue;
import java.util.StringTokenizer;

public class p2583 {
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static int n, m, k;
	static int[][] graph = new int[101][101];
	static boolean[][] visit = new boolean[101][101];
	static Queue<int[]> q = new ArrayDeque<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());

			for (int r = y1; r < y2; r++) {
				for (int c = x1; c < x2; c++) {
					graph[r][c] = 1;
				}
			}
		}

		ArrayList<Integer> result = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] || graph[i][j] == 1)
					continue;

				q.add(new int[] {i, j});
				visit[i][j] = true;
				int region = 0;
				while (!q.isEmpty()) {
					region++;
					int curX = q.peek()[0];
					int curY = q.peek()[1];
					q.poll();

					for (int k = 0; k < 4; k++) {
						int nextX = curX + dx[k];
						int nextY = curY + dy[k];
						if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
							continue;
						if (visit[nextX][nextY] || graph[nextX][nextY] == 1)
							continue;

						q.add(new int[] {nextX, nextY});
						visit[nextX][nextY] = true;
					}
				}

				result.add(region);
				Collections.sort(result);
			}
		}
		System.out.println(result.size());
		for (Integer region : result) {
			System.out.print(region + " ");
		}
	}
}
