package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p2623 {
    static int N, M;
    static int[] count;
    static ArrayList<Integer>[] graph;
    static PriorityQueue<Integer> pq;
    static Queue<Integer> answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        count = new int[N + 1];
        pq = new PriorityQueue<>();
        answer = new ArrayDeque<>();

        graph = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int[] arr = new int[num];
            for (int j = 0; j < num; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }

            for (int j = 0; j < num; j++) {
                for (int k = j + 1; k < num; k++) {
                    graph[arr[j]].add(arr[k]);
                    count[arr[k]]++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (count[i] == 0) {
                pq.add(i);
            }
        }

        while (!pq.isEmpty()) {
            int now = pq.poll();
            answer.add(now);

            for (int i = 0; i < graph[now].size(); i++) {
                count[graph[now].get(i)]--;
                if (count[graph[now].get(i)] == 0) {
                    pq.add(graph[now].get(i));
                }
            }
        }

        if (answer.size() == N) {
            while (!answer.isEmpty()) {
                System.out.println(answer.poll());
            }
        } else {
            System.out.println("0");
        }
    }
}
