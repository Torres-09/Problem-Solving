package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class p1941 {
    static char[][] graph;
    static int[][] arr;
    static boolean[][] include;
    static boolean[][] visit;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int count;
    static int sCount;
    static int answer;
    static ArrayList<Integer> com = new ArrayList<>();

    static void combination(int a, int cnt) {
        // 연결되는 건 지 확인
        if (com.size() == 7) {
            if (sCount < 4) return;

            Queue<int[]> q = new ArrayDeque<>();
            visit = new boolean[5][5];

            q.add(new int[]{arr[com.get(0)][0], arr[com.get(0)][1]});
            visit[arr[com.get(0)][0]][arr[com.get(0)][1]] = true;
            count = 1;
            while (!q.isEmpty()) {
                int curX = q.peek()[0];
                int curY = q.peek()[1];
                q.poll();

                for (int j = 0; j < 4; j++) {
                    int nextX = curX + dx[j];
                    int nextY = curY + dy[j];

                    if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5) continue;
                    if (!include[nextX][nextY]) continue;
                    if (visit[nextX][nextY]) continue;

                    q.add(new int[]{nextX, nextY});
                    visit[nextX][nextY] = true;
                    count++;
                }
            }

            if (count == com.size()) {
                answer++;
            }

            return;
        }

        for (int i = a; i < 25; i++) {
            com.add(i);
            include[arr[i][0]][arr[i][1]] = true;
            if (graph[arr[i][0]][arr[i][1]] == 'S') sCount++;
            combination(i + 1, cnt + 1);
            include[arr[i][0]][arr[i][1]] = false;
            if (graph[arr[i][0]][arr[i][1]] == 'S') sCount--;
            com.remove(com.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        graph = new char[5][5];
        arr = new int[25][2];
        include = new boolean[5][5];
        for (int i = 0; i < 5; i++) {
            graph[i] = br.readLine().toCharArray();
        }
        for (int i = 0; i < 25; i++) {
            arr[i][0] = i / 5;
            arr[i][1] = i % 5;
        }

        combination(0, 0);

        System.out.println(answer);
    }
}
