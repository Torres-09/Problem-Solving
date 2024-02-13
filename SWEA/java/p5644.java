package com.sw.java;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p5644 {
    static int t, M, A;
    static int answer;
    static int[] moveA;
    static int[] moveB;
    static BC[] bcs;
    // 정지, 상, 우, 하, 좌
    static int dx[] = {0, -1, 0, 1, 0};
    static int dy[] = {0, 0, 1, 0, -1};

    static class BC {
        Point point;
        int range;
        int per;

        public BC(int x, int y, int range, int per) {
            point = new Point(y, x);
            this.range = range;
            this.per = per;
        }
    }

    static boolean check(int x, int y, int bcNo) {
        return Math.abs(bcs[bcNo].point.x - x) + Math.abs(bcs[bcNo].point.y - y) <= bcs[bcNo].range;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int a = 1; a <= t; a++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
            moveA = new int[M];
            moveB = new int[M];
            bcs = new BC[A];
            answer = 0;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                moveA[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                moveB[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < A; i++) {
                st = new StringTokenizer(br.readLine());
                // x, y, range, performance
                bcs[i] = new BC(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            // 여기까지 입력

            // 처음 시작하는 위치
            int aCurX = 1;
            int aCurY = 1;
            int bCurX = 10;
            int bCurY = 10;

            // 0의 시간에서 한 번 충전한다.
            for (int j = 0; j < A; j++) {
                for (int k = 0; k < A; k++) {
                    int result = 0;
                    // 두 발전소 선택이 같은 경우 -> 성능이 절반이 된다.
                    // 둘 다 발전소에서 충전을 하는 경우에만 성능을 반으로 쪼개야한다.
                    if (j == k) {
                        if (check(aCurX, aCurY, j) && check(bCurX, bCurY, k)) {
                            result += bcs[j].per / 2;
                            result += bcs[k].per / 2;
                        } else if (check(aCurX, aCurY, j) && !check(bCurX, bCurY, k)) {
                            result += bcs[j].per;
                        } else if (!check(aCurX, aCurY, j) && check(bCurX, bCurY, k)) {
                            result += bcs[k].per;
                        }
                    } else {
                        if (check(aCurX, aCurY, j)) result += bcs[j].per;
                        if (check(bCurX, bCurY, k)) result += bcs[k].per;
                    }

                    answer = Math.max(answer, result);
                }
            }

            int Anx = aCurX;
            int Any = aCurY;
            int Bnx = bCurX;
            int Bny = bCurY;

            // 이제 움직인다.
            for (int i = 0; i < M; i++) {
                Anx += dx[moveA[i]];
                Any += dy[moveA[i]];
                Bnx += dx[moveB[i]];
                Bny += dy[moveB[i]];
                int temp = 0;

                // A에서는 j 번째 발전소를 선택
                // B에서는 k 번째 발전소를 선택
                // 둘 중 합이 큰 것으로 결정한다.
                for (int j = 0; j < A; j++) {
                    for (int k = 0; k < A; k++) {
                        int result = 0;
                        // 두 발전소 선택이 같은 경우 -> 성능이 절반이 된다.
                        // 둘 다 발전소에서 충전을 하는 경우에만 성능을 반으로 쪼개야한다.
                        if (j == k) {
                            if (check(Anx, Any, j) && check(Bnx, Bny, k)) {
                                result += bcs[j].per / 2;
                                result += bcs[k].per / 2;
                            } else if (check(Anx, Any, j) && !check(Bnx, Bny, k)) {
                                result += bcs[j].per;
                            } else if (!check(Anx, Any, j) && check(Bnx, Bny, k)) {
                                result += bcs[k].per;
                            }
                        } else {
                            if (check(Anx, Any, j)) result += bcs[j].per;
                            if (check(Bnx, Bny, k)) result += bcs[k].per;
                        }

                        temp = Math.max(temp, result);
                    }
                }
                answer += temp;
            }

            System.out.println("#" + a + " " + answer);
        }
    }
}

// 최대 100 칸 이동 가능
// 한 칸에서 체크해야 하는 발전소는 최대 8개
// 2 중 반복문으로 64개 체크
// 100 x 64 -> 6400