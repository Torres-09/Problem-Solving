package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1766 {
    static int N, M;
    static int[] count;
    static ArrayList<Integer>[] arr;
    static PriorityQueue<int[]> pq;
    static int cnt;
    static StringBuilder answer = new StringBuilder();
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        count = new int[N + 1];
        arr = new ArrayList[N + 1];
        visit = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }

        pq = new PriorityQueue<>((o1, o2) -> {
            if (o2[1] != o1[1]) {
                return Integer.compare(o1[1], o2[1]);
            } else {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            count[b]++;
            arr[a].add(b);
        }

        for (int i = 1; i <= N; i++) {
            if (count[i] == 0) {
                pq.add(new int[]{i, count[i]});
            }
        }

        while (!pq.isEmpty()) {
            int[] problem = pq.poll();
            int num = problem[0];
            if (visit[num]) continue;
            visit[num] = true;
            cnt++;

            answer.append(String.format("%d ", num));
            for (int i = 0; i < arr[num].size(); i++) {
                if (visit[arr[num].get(i)]) continue;
                count[arr[num].get(i)]--;
                pq.add(new int[]{arr[num].get(i), count[arr[num].get(i)]});
            }
        }
        System.out.println(answer.toString().trim());
    }
}
