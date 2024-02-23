package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p4963 {
    static int w, h;
    static int[][] graph;
    static boolean[][] visit;
    static int[] dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    static int[] dy = {0, 0, 1, -1, -1, 1, -1 ,1};
    static int answer;

    static void DFS(int x, int y) {
        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
            if(visit[nextX][nextY]) continue;
            if(graph[nextX][nextY] == 0) continue;

            visit[nextX][nextY] = true;
            DFS(nextX, nextY);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            graph = new int[h][w];
            visit = new boolean[h][w];
            answer = 0;

            if(w == 0 || h == 0) return;

            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    graph[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (graph[i][j] == 1 && !visit[i][j]) {
                        answer++;
                        DFS(i, j);
                    }
                }
            }

            System.out.println(answer);
        }
    }
}
