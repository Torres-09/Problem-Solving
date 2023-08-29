package com.baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
1. summary
	상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
2. strategy
3. note : 100 * 100 * 100(사람 최대 이동) = 1000000
	2 ≤ R, C(공간) ≤ 100, 0 ≤ M(상어 수) ≤ R×C
	1 ≤ r(상어 시작행) ≤ R, 1 ≤ c(상어 시작열) ≤ C, 0 ≤ s(속력) ≤ 1000, 1 ≤ d(방향) ≤ 4, 1 ≤ z(크기) ≤ 10000
*/
public class BOJ17143 {

    static public class Shark {
        int r, c, s, d, z;

        public Shark(int r, int c, int s, int d, int z) {
            this.r = r;
            this.c = c;
            this.s = s;
            this.d = d;
            this.z = z;
        }
    }

    // 1 : 위, 2: 아래, 3: 오른쪽, 4 : 왼쪽
    static int dir[][] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    static int R, C, M, board[][];
    static Shark sharkList[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken()); // 행
        C = Integer.parseInt(st.nextToken()); // 열
        M = Integer.parseInt(st.nextToken()); // 상어수

        board = new int[R + 2][C + 2]; // 상어 위치(행 : 1~R, 열 : 1~C)
        sharkList = new Shark[M + 1];
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()); // 상어 초기 행
            int c = Integer.parseInt(st.nextToken()); // 상어 초기 열
            int s = Integer.parseInt(st.nextToken()); // 상어 속력
            int d = Integer.parseInt(st.nextToken()); // 상어 방향
            int z = Integer.parseInt(st.nextToken()); // 상어 크기

            board[r][c] = i; // 상어 위치
            sharkList[i] = new Shark(r, c, s, d, z); // 상어 정보
        }

        int startPerson = 0;
        int sumSharkZ = 0;

        while (startPerson < C) { // 최대 100번
            // 1. 낚시왕 이동
            startPerson++;

            // 2. 낚시 (startPerson 열에 상어 있는지 체크)
            int moveX = 0;
            while (true) { // 최대 100번
                moveX++; // 1행부터 상어 탐색
                if (board[moveX][startPerson] > 0) { // 해당 위치에 상어 있으면

                    int sharkNumber = board[moveX][startPerson];
                    sumSharkZ += sharkList[sharkNumber].z;

                    board[moveX][startPerson] = 0; // 수조에서 상어 삭제
                    sharkList[sharkNumber] = null; // 상어 목록에서 상어 정보 삭제

                    break; // 상어 잡으면 바로 종료
                }
                if (moveX == R) break; // R행까지 탐색 했으면 종료
            }

            for (int i = 0; i <= R; i++) {
                for (int j = 0; j <= C; j++) {
                    board[i][j] = 0;
                }
            }

            // 3. 상어 이동
            for (int i = 1; i <= M; i++) { // 최대 10000번
                if (sharkList[i] == null) continue; // 이미 잡힌 상어

                Shark shark = sharkList[i];

                board[shark.r][shark.c] = 0; // 이동하기 전에 흔적 지우기

                for (int k = 1; k <= shark.s; k++) { // 상어 이동 (최대 1000번)
                    // 방향 전환
                    if (shark.c == 1 && shark.d == 4) shark.d = 3; // 왼쪽 모서리인데 방향이 왼쪽인 경우
                    else if (shark.c == C && shark.d == 3) shark.d = 4; // 오른쪽 모서리인데 방향이 오른쪽인 경우
                    else if (shark.r == 1 && shark.d == 1) shark.d = 2; // 위쪽 모서리인데 방향이 위쪽인 경우
                    else if (shark.r == R && shark.d == 2) shark.d = 1; // 아래쪽 모서리인데 방향이 아래쪽인 경우

                    shark.r += dir[shark.d][0];
                    shark.c += dir[shark.d][1]; // 한 칸 이동
                }

                // 상어 최종 도착지 체크 (상어 중복 체크)
                if (board[shark.r][shark.c] != 0) { // 상어 위치 겹치는 경우
                    int othersharkNumber = board[shark.r][shark.c];

                    if (sharkList[othersharkNumber].z > sharkList[i].z) { // 기존 상어가 더 큰 경우
                        sharkList[i] = null; // 상어 죽음
                    } else { // 새로 이동하는 상어가 더 큰 경우 (둘이 크기가 동일한 경우는 없다.)
                        board[shark.r][shark.c] = i; // 상어 교체
                        sharkList[othersharkNumber] = null; // 기존 상어 죽음
                    }
                } else { // 상어 위치 겹치지 않는 경우
                    board[shark.r][shark.c] = i; // 이동 완료
                }
            }
        }

        System.out.println(sumSharkZ);
    }
}
