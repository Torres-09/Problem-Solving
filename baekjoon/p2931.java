package com.baekjoon;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p2931 {
    static int r, c;
    static char[][] board;
    static Point m, z;
    static char[] blocks = {'|', '-', '+', '1', '2', '3', '4'};
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        board = new char[r][c];

        // 블록이 M과 Z 다음에 바로 없어졌다고 하더라도 M 혹은 Z 둘 중 하나에서는 출발이 가능하다.
        for (int i = 0; i < r; i++) {
            String row = br.readLine();
            for (int j = 0; j < c; j++) {
                board[i][j] = row.charAt(j);
                if (board[i][j] == 'M') m = new Point(i, j);
                else if (board[i][j] == 'Z') z = new Point(i, j);
            }
        }

        board[m.x][m.y] = '+';

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] != '.') continue;

                for (int k = 0; k < 7; k++) {
                    board[i][j] = blocks[k];
                    for (int dir = 0; dir < 4; dir++) {
                        Point pre = m;
                        Point cur = new Point(m.x + dx[dir], m.y + dy[dir]);

                        if (cur.x < 0 || cur.x >= r || cur.y < 0 || cur.y >= c) continue;
                        if(board[cur.x][cur.y] == '.') continue;

                        while (true) {
                            Point next = move(cur.x, cur.y, pre.x, pre.y);
                            if(next == null) break;
                            if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c) break;

                            pre = cur;
                            cur = next;

                            if (next.x == z.x && next.y == z.y) {
                                System.out.println((i+1) + " " + (j+1) + " " + blocks[k]);
                                return;
                            }
                        }
                    }
                }

                board[i][j] = '.';
            }
        }
    }

    // 그 다음 칸을 반환한다.
    static Point move(int x, int y, int preX, int preY) {
        if (board[x][y] == '.') return null;
        if (board[x][y] == '|') {
            if (board[preX][preY] == '-') return null;
        }
        if (board[x][y] == '-') {
            if (board[preX][preY] == '|') return null;
        }

        if (board[x][y] == '|') {
            // 위에서 내려온다
            if (preX < x && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '4'))
                return new Point(x + 1, y);
                // 아래에서 올라온다
            else if (preX > x && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '2' || board[preX][preY] == '3'))
                return new Point(x - 1, y);
        } else if (board[x][y] == '-') {
            // 왼쪽에서 온다
            if (preY < y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '2'))
                return new Point(x, y + 1);
                // 오른쪽에서 온다.
            else if (preY > y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '3' || board[preX][preY] == '4'))
                return new Point(x, y - 1);
        } else if (board[x][y] == '+') {
            // 왼쪽에서 온다.
            if (preX == x && preY < y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '2'))
                return new Point(x, y + 1);
                // 오른쪽에서 온다.
            else if (preX == x && preY > y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '3' || board[preX][preY] == '4'))
                return new Point(x, y - 1);
                // 위에서 온다.
            else if (preX < x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '4'))
                return new Point(x + 1, y);
                // 아래에서 온다.
            else if (preX > x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '2' || board[preX][preY] == '3'))
                return new Point(x - 1, y);
        } else if (board[x][y] == '1') {
            // 아래에서 온다.
            if (preX > x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '3' || board[preX][preY] == '2'))
                return new Point(x, y + 1);
                // 오른쪽에서 온다.
            else if (preX == x && preY > y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '3' || board[preX][preY] == '4'))
                return new Point(x + 1, y);
        } else if (board[x][y] == '2') {
            // 위에서 온다.
            if (preX < x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '4'))
                return new Point(x, y + 1);
                // 오른쪽에서 온다.
            else if (preX == x && preY > y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '3' || board[preX][preY] == '4'))
                return new Point(x - 1, y);
        } else if (board[x][y] == '3') {
            // 왼쪽에서 온다.
            if (preX == x && preY < y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '2'))
                return new Point(x - 1, y);
                // 위에서 온다.
            else if (preX < x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '4'))
                return new Point(x, y - 1);
        } else if (board[x][y] == '4') {
            // 왼쪽에서 온다.
            if (preX == x && preY < y && (board[preX][preY] == '-' || board[preX][preY] == '+' || board[preX][preY] == '1' || board[preX][preY] == '2'))
                return new Point(x + 1, y);
                // 아래에서 온다.
            else if (preX > x && preY == y && (board[preX][preY] == '|' || board[preX][preY] == '+' || board[preX][preY] == '2' || board[preX][preY] == '3'))
                return new Point(x, y - 1);
        }

        return null;
    }
}
