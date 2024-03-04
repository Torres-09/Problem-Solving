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
    static PriorityQueue<Integer> pq;
    static int cnt;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        count = new int[N + 1];
        arr = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }

        pq = new PriorityQueue<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            count[b]++;
            arr[a].add(b);
        }

        for (int i = 1; i <= N; i++) {
            if (count[i] == 0) {
                pq.add(i);
            }
        }

        while (!pq.isEmpty()) {
            int problem = pq.poll();
            cnt++;

            answer.append(String.format("%d ", problem));
            for (int i = 0; i < arr[problem].size(); i++) {
                count[arr[problem].get(i)]--;
                if (count[arr[problem].get(i)] == 0) {
                    pq.add(arr[problem].get(i));
                }
            }
        }
        System.out.println(answer.toString().trim());
    }
}
