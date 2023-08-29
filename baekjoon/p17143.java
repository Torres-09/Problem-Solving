package com.baekjoon;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 최대 사람은 100번 움직인다.
 * 상어는 최대 10000마리 있다.
 * 각 상어에 대해 1만 번 움직이는 연산
 * 땅에서 가까운 상어를 찾는다. 최대 100의 거리가 있고 100번 움직이니까 10000
 */

public class p17143 {
    static int r, c, m;
    static Shark[] sharks;
    static boolean[] isDie;
    static int[][] board;
    static int answer;


    // 위 아래 오른쪽 왼쪽 ( 1, 2, 3, 4 )
    static int[] dx = {0, -1, 1, 0, 0};
    static int[] dy = {0, 0, 0, 1, -1};

    static class Shark {
        Point point;
        int s, d, z;

        public Shark(Point point, int s, int d, int z) {
            this.point = point;
            this.s = s;
            this.d = d;
            this.z = z;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 각 칸에 몇 번 상어가 있는 지
        board = new int[r + 1][c + 1];
        sharks = new Shark[m];
        isDie = new boolean[m];
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                board[i][j] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            sharks[i] = new Shark(new Point(x, y), s, d, z);
            board[x][y] = i;
        }

        // 10000 * 100 -> 1000000

        // 열 만큼 이동한다.
        for (int i = 1; i <= c; i++) {
            // 1. 먼저 상어를 잡는다.
            // i 번째 열에서 가장 가까운 상어를 찾는다.
            for (int j = 1; j <= r; j++) {
                // 상어를 발견했다.
                if (board[j][i] != -1) {
//                    System.out.println("지금 열이 : " + i + " 지금 먹은 상어의 크기 : " + sharks[board[j][i]].z);
                    // 상어를 죽이고 빈 칸으로 만든다.
                    isDie[board[j][i]] = true;
                    answer += sharks[board[j][i]].z;
                    board[j][i] = -1;
                    break;
                }
            }

            for (int a = 0; a <= r; a++) {
                for (int b = 0; b <= c; b++) {
                    board[a][b] = -1;
                }
            }

            // 2. 각 상어가 이동한다.
            for (int j = 0; j < m; j++) {
                if(isDie[j]) continue;

                Shark shark = sharks[j];
                int z = shark.z;
                int[] change = move(shark.point.x, shark.point.y, shark.d, shark.s);
                shark.point.x = change[0];
                shark.point.y = change[1];
                shark.d = change[2];

                // 상어가 이미 있음
                if (board[shark.point.x][shark.point.y] != -1) {
                    if (sharks[board[shark.point.x][shark.point.y]].z > z) {
                        // 이미 있던 상어가 더 큰 상어다. 새로운 상어는 바로 사망
                        isDie[j] = true;
                    } else {
                        // 이미 잇던 상어보다 더 큰 상어이다. 기존 상어 사망. 새로운 상어가 칸을 차지한다.
                        isDie[board[shark.point.x][shark.point.y]] = true;
                        board[shark.point.x][shark.point.y] = j;
                    }
                } else { // 상어가 아직 없음
                    board[shark.point.x][shark.point.y] = j;
                }
            }
        }

        System.out.println(answer);
    }

    static int[] move(int x, int y, int dir, int s) {
        int nx = x;
        int ny = y;

        for (int i = 0; i < s; i++) {
            // 방향 체크
            if(nx == 1 && dir == 1) dir = 2;
            if(nx == r && dir == 2) dir = 1;
            if(ny == 1 && dir == 4) dir = 3;
            if(ny == c && dir == 3) dir = 4;

            // 이동
            nx += dx[dir];
            ny += dy[dir];
        }

        return new int[]{nx, ny, dir};
    }
}
