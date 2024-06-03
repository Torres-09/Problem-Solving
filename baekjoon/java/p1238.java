package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1238 {
    static int N,M, X;
    static ArrayList<int[]>[] adjList;
    static ArrayList<int[]>[] reverseAdjList;
    static int[] dist;
    static int[] reverseDist;
    static int answer;

    static int[] dijkstra(ArrayList<int[]>[] adjList, int[] dist) {
        dist = new int[N + 1];
        Arrays.fill(dist, 100_000_000);
        dist[X] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o1->o1[1]));
        pq.add(new int[]{X, 0});

        while (!pq.isEmpty()) {
            int[] now = pq.poll();
            int nowVertex = now[0];

            for (int i = 0; i < adjList[nowVertex].size(); i++) {
                int nextVertex = adjList[nowVertex].get(i)[0];
                int cost = adjList[nowVertex].get(i)[1];

                if (dist[nextVertex] > dist[nowVertex] + cost) {
                    dist[nextVertex] = dist[nowVertex] + cost;
                    pq.add(new int[] {nextVertex, dist[nextVertex]});
                }
            }
        }

        return dist;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        adjList = new ArrayList[N+1];
        reverseAdjList = new ArrayList[N+1];
        dist = new int[N + 1];
        reverseDist = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            adjList[i] = new ArrayList<>();
            reverseAdjList[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adjList[start].add(new int[] {end, cost});
            reverseAdjList[end].add(new int[] {start, cost});
        }

        dist = dijkstra(adjList, dist);
        reverseDist = dijkstra(reverseAdjList, reverseDist);

        for (int i = 1; i <= N; i++) {
            answer = Math.max(dist[i] + reverseDist[i], answer);
        }

        System.out.println(answer);
    }
}

// https://www.acmicpc.net/problem/1238