package com.sw.java;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1873 {
    static int t, h, w, n;
    static char[][] board;
    static char[] cmd;

    static Point tank;

    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            board = new char[h][w];
            for (int j = 0; j < h; j++) {
                char[] row = br.readLine().toCharArray();
                for (int k = 0; k < w; k++) {
                    board[j][k] = row[k];
                    if (board[j][k] == '<' || board[j][k] == '>' || board[j][k] == '^' || board[j][k] == 'v')
                        tank = new Point(j, k);
                }
            }

            n = Integer.parseInt(br.readLine());
            cmd = new char[n];
            cmd = br.readLine().toCharArray();
            for (int j = 0; j < cmd.length; j++) {
                if (cmd[j] == 'S') {
                    shoot();
                } else {
                    move(cmd[j]);
                }
            }

            System.out.print("#" + i + " ");
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < w; k++) {
                    System.out.print(board[j][k]);
                }
                System.out.println();
            }
        }
    }

    private static void move(char direction) {
        int dir;
        int x = tank.x;
        int y = tank.y;
        if (direction == 'U'){
            dir = 0;
            board[x][y] = '^';
        }
        else if(direction == 'D'){
            dir = 1;
            board[x][y] = 'v';
        }
        else if(direction == 'L'){
            dir = 2;
            board[x][y] = '<';
        }
        else{
            dir = 3;
            board[x][y] = '>';
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= h || ny <0 || ny >= w) return;
        if(board[nx][ny] != '.') return;

        board[nx][ny] = board[x][y];
        board[x][y] = '.';
        tank.x = nx;
        tank.y = ny;
    }

    private static void shoot() {
        int dir;
        int x = tank.x;
        int y = tank.y;
        if(board[x][y] == '<') dir = 2;
        else if(board[x][y] == '>') dir = 3;
        else if(board[x][y] == '^') dir = 0;
        else dir = 1;

        int nx = x;
        int ny = y;

        while (true) {
            nx += dx[dir];
            ny += dy[dir];

            // 맵을 벗어남
            if(nx < 0 || nx >= h || ny <0 || ny >= w) break;
            // 강철로 된 벽이다.
            if(board[nx][ny] == '#') break;
            // 벽돌로 된 벽이다.
            if(board[nx][ny] == '*'){
                board[nx][ny] = '.';
                break;
            }
        }
    }
}
