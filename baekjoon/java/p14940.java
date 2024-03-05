package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class p14940 {
    static int N, M;
    static int[][] graph;
    static int[][] answer;
    static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static Queue<int[]> q = new ArrayDeque<>();
    static boolean[][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N][M];
        answer = new int[N][M];
        visit = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());

                if (graph[i][j] == 2) {
                    q.add(new int[]{i, j});
                    visit[i][j] = true;
                }
            }
        }

        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
//            System.out.println("현재 위치는 x:" + x + " y:" + y);
            q.poll();

            for (int i = 0; i < 4; i++) {
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];

                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
                if (visit[nextX][nextY]) continue;
                if (graph[nextX][nextY] == 0) continue;

                visit[nextX][nextY] = true;
                answer[nextX][nextY] = answer[x][y] + 1;
                q.add(new int[]{nextX, nextY});
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (answer[i][j] == 0 && graph[i][j] == 1) answer[i][j] = -1;
                System.out.print(answer[i][j] + " ");
            }
            System.out.println();
        }
    }
}
