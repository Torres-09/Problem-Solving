package com.baekjoon;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p10026 {
    static char[][] graph;
    static int n;
    static boolean[][] Visit;
    static Queue<Point> q = new LinkedList<>();
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};
    static int Count = 0;

    public static void BFS(int n1, int n2) {
        if (Visit[n1][n2]) return;

        q.add(new Point(n1, n2));
        Visit[n1][n2] = true;

        while (!q.isEmpty()) {
            Point pos = q.poll();
            int x = pos.x;
            int y = pos.y;

            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
                if (Visit[next_x][next_y]) continue;

                if (graph[x][y] == graph[next_x][next_y]) {
                    Visit[next_x][next_y] = true;
                    q.add(new Point(next_x, next_y));
                }
            }
        }

        Count++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        graph = new char[n][n];
        Visit = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            graph[i] = br.readLine().toCharArray();
        }

        int a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                BFS(i, j);
            }
        }

        a = Count;
        Count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 'R') graph[i][j] = 'G';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Visit[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                BFS(i, j);
            }
        }

        b = Count;

        System.out.println(a + " " + b);
    }
}
