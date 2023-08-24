package com.baekjoon;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p15683 {
    static int n, m;
    static int[][] board = new int[9][9];
    static int[][] temp_board = new int[9][9];
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static ArrayList<Point> cctv = new ArrayList<>();
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] >= 1 && board[i][j] <= 5) cctv.add(new Point(i, j));
                if (board[i][j] == 0) answer++;
            }
        }

        for (int i = 0; i < (1 << (2 * cctv.size())); i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    temp_board[j][k] = board[j][k];
                }
            }

            int count = i;
            for (int j = 0; j < cctv.size(); j++) {
                int dir = count % 4;
                count /= 4;

                int x = cctv.get(j).x;
                int y = cctv.get(j).y;

                if (board[x][y] == 1) {
                    check(x, y, dir);
                }
                else if (board[x][y] == 2) {
                    check(x, y, dir);
                    check(x, y, dir + 2);
                }
                else if (board[x][y] == 3) {
                    check(x, y, dir);
                    check(x, y, dir + 1);
                }
                else if (board[x][y] == 4) {
                    check(x, y, dir);
                    check(x, y, dir + 1);
                    check(x, y, dir + 2);
                }
                else {
                    check(x, y, dir);
                    check(x, y, dir+1);
                    check(x, y, dir+2);
                    check(x, y, dir+3);
                }
            }

            int temp = 0;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    if (temp_board[a][b] == 0)temp++;
                }
            }
            answer = Math.min(temp, answer);
        }
        System.out.println(answer);
    }

    static void check(int x, int y, int dir) {
        dir %= 4;
        while (true) {
            x += dx[dir];
            y += dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m || temp_board[x][y] == 6) return;
            if (temp_board[x][y] != 0) continue;
            temp_board[x][y] = 7;
        }
    }
}