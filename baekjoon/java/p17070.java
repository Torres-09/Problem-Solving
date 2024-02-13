package com.baekjoon.java;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class p17070 {
    static int[] dx = {-1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1};
    static int[] dy = {0, 0, -1, 1, -2, -1, 1, 2, -2, -1, 1, 2};
    static int k, w, h;
    static int[][] board;
    static boolean[][][] isVisit;

    static class Horse {
        Point point;
        int cnt;
        int horse;

        public Horse(Point point, int cnt, int horse) {
            this.point = point;
            this.cnt = cnt;
            this.horse = horse;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        k = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        board = new int[h + 1][w + 1];
        isVisit = new boolean[h + 1][w + 1][31];

        for (int i = 0; i < h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Queue<Horse> q = new ArrayDeque<>();
        q.add(new Horse(new Point(0, 0), 0, 0));
        isVisit[0][0][0] = true;

        while (!q.isEmpty()) {
            Horse horse = q.poll();
            Point cur = horse.point;
            if (cur.x == h - 1 && cur.y == w - 1) {
                System.out.println(horse.cnt);
                return;
            }

            for (int i = 0; i < dx.length; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                // 말의 움직임을 더 이상 이용할 수 없음
                if (horse.horse == k && i >= 4) continue;
                // 범위를 벗어남
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                // 벽 임
                if (board[nx][ny] == 1) continue;
                if (i >= 4) {
                    if (isVisit[nx][ny][horse.horse + 1]) continue;
                }
                if (i < 4) {
                    if (isVisit[nx][ny][horse.horse]) continue;
                }
                // 말이 움직입니다.
                if (i >= 4) {
                    isVisit[nx][ny][horse.horse + 1] = true;
                    q.add(new Horse(new Point(nx, ny), horse.cnt + 1, horse.horse + 1));
                } else {
                    isVisit[nx][ny][horse.horse] = true;
                    q.add(new Horse(new Point(nx, ny), horse.cnt + 1, horse.horse));
                }
            }
        }

        System.out.println(-1);
    }
}
