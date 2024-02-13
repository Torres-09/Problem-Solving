package com.sw.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * 1이 더 큰 상하좌우 만 이동이 가능하다.
 */

public class p1861 {
    static int t;
    static int n;
    static int arr[][];
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    static int Visit[][] = new int[1001][1001];
    static int answer;
    static int answer_count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            // 초기화
            arr = new int[1001][1001];
            // 지점의 숫자
            answer = Integer.MAX_VALUE;
            // 방문 가능한 방의 개수
            answer_count = -1;

            // 방 사이즈 n 입력받기
            n = Integer.parseInt(br.readLine());
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    Visit[j][k] = 0;
                }
            }

            // 전체 방 입력받기
            for (int j = 0; j < n; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int k = 0; k < n; k++) {
                    arr[j][k] = Integer.parseInt(st.nextToken());
                }
            }

            // 전체에서 DFS를 실시한다.
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (Visit[j][k] == 0)
                        DFS(j, k);
                }
            }

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (answer_count < Visit[j][k]) {
                        answer_count = Visit[j][k];
                        answer = arr[j][k];
                    } else if (answer_count == Visit[j][k]) {
                        if (answer > arr[j][k]) {
                            answer = arr[j][k];
                        }
                    }
                }
            }

            System.out.println("#" + i + " " + answer + " " + (answer_count + 1));
        }
    }

    static int DFS(int x, int y) {
        // 다음 방에 방문한다.
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 배열을 벗어남
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            // 이미 방문함
            if (Visit[nx][ny] != 0) {
                if (arr[nx][ny] - arr[x][y] == 1) {
                    Visit[x][y] = Visit[nx][ny] + 1;
                }
                continue;
            }
            // 다음 칸에 방문할 수 없음
            if (arr[nx][ny] - arr[x][y] != 1) continue;

            // 갈 수 있는 곳이 한 곳 뿐 일 예정
            Visit[x][y] = DFS(nx, ny);
            break;
        }

        return Visit[x][y] + 1;
    }
}
