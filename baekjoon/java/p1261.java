package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p1261 {
    static int N, M;
    static int[][] graph;
    static PriorityQueue<int[]> pq;
    static boolean[][] visit;
    static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        graph = new int[N][M];
        visit = new boolean[N][M];
        pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[2]));

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                graph[i][j] = line.charAt(j) - '0';
            }
        }

        pq.add(new int[]{0, 0, 0});
        visit[0][0] = true;
        while (!pq.isEmpty()) {
            int[] info = pq.poll();
            int x = info[0];
            int y = info[1];
            int count = info[2];

            if (x == N - 1 && y == M - 1) {
                System.out.println(count);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];

                if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
                if(visit[nextX][nextY]) continue;

                if (graph[nextX][nextY] == 1) {
                    pq.add(new int[]{nextX, nextY, count + 1});
                } else {
                    pq.add(new int[]{nextX, nextY, count});
                }
                visit[nextX][nextY] = true;
            }
        }
    }
}
