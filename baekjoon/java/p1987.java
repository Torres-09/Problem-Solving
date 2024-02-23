package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1987 {
    static int R, C;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean[][] visit;
    static char[][] graph;
    static boolean[] alpha;
    static int answer;

    static void DFS(int x, int y, int cnt) {
        answer = Math.max(answer, cnt);

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
            if(visit[nextX][nextY]) continue;
            if(alpha[graph[nextX][nextY] - 'A']) continue;

            alpha[graph[nextX][nextY] - 'A'] = true;
            visit[nextX][nextY] = true;
            DFS(nextX, nextY, cnt+1);
            alpha[graph[nextX][nextY] - 'A'] = false;
            visit[nextX][nextY] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        graph = new char[R][C];
        visit = new boolean[R][C];
        alpha = new boolean[26];

        for (int i = 0; i < R; i++) {
            String row = br.readLine();
            for (int j = 0; j < C; j++) {
                graph[i][j] = row.charAt(j);
            }
        }

        visit[0][0] = true;
        alpha[graph[0][0] - 'A'] = true;
        DFS(0, 0, 1);

        System.out.println(answer);
    }
}
