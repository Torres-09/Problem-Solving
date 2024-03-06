package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p3655 {
    static int T, N, M;
    static int[] lastScore;
    static int[][] graph;
    static int[] count;
    static PriorityQueue<Integer> pq;
    static ArrayList<Integer> answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            graph = new int[N + 1][N + 1];
            lastScore = new int[N + 1];
            count = new int[N + 1];
            pq = new PriorityQueue<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                lastScore[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 1; i <= N; i++) {
                for (int j = i + 1; j <= N; j++) {
                    // j가 나오려면 i가 앞에 나와야 한다.
                    graph[lastScore[i]][lastScore[j]] = 1;
                    // j의 앞에 count 만큼의 무언가 있어야 한다.
                    count[lastScore[j]]++;
                }
            }

            M = Integer.parseInt(br.readLine());
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                // a와 b의 상대적인 등수가 변한다.
                // a가 원래 앞에 오는 경우
                if (graph[a][b] == 1) {
                    graph[a][b] = 0;
                    graph[b][a] = 1;
                    count[a] += 1;
                    count[b] -= 1;
                } else {
                    graph[a][b] = 1;
                    graph[b][a] = 0;
                    count[a] -= 1;
                    count[b] += 1;
                }
            }

            for (int i = 1; i <= N; i++) {
                if (count[i] == 0) pq.add(i);
            }

            answer = new ArrayList<>();

            while (!pq.isEmpty()) {
                int now = pq.poll();
                answer.add(now);

                for (int i = 1; i <= N; i++) {
                    if (graph[now][i] == 1) {
                        graph[now][i] = 0;
                        count[i] -= 1;
                        if (count[i] == 0) pq.add(i);
                    }
                }
            }

            if (answer.size() == N) {
                for (int i : answer) {
                    System.out.print(i + " ");
                }
                System.out.println();
            } else {
                System.out.println("IMPOSSIBLE");
            }
        }
    }
}
