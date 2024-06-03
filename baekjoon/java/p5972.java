package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p5972 {

    static int N, M;

    static ArrayList<int[]>[] adjList;
    static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adjList = new ArrayList[N + 1];
        dist = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            adjList[i] = new ArrayList<>();
            dist[i] = 1000000000;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjList[a].add(new int[]{b, cost});
            adjList[b].add(new int[]{a, cost});
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));
        pq.add(new int[]{1, 0});
        dist[1] = 0;

        while (!pq.isEmpty()) {
            int now = pq.peek()[0];
            int cost = pq.peek()[1];
            pq.poll();

            for (int i = 0; i < adjList[now].size(); i++) {
                int next = adjList[now].get(i)[0];
                int nextCost = adjList[now].get(i)[1];
                if (dist[next] > dist[now] + nextCost) {
                    dist[next] = dist[now] + nextCost;
                    pq.add(new int[]{next, dist[next]});
                }
            }
        }

        System.out.println(dist[N]);
    }
}
