package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1916 {
    static int N, M, A, B;

    static ArrayList<ArrayList<Edge>> edgeList;

    static int[] dist;

    static class Edge implements Comparable<Edge> {
        int to, weight;

        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        edgeList = new ArrayList<>();
        dist = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            edgeList.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            int start, end, weight;
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());
            edgeList.get(start).add(new Edge(end, weight));
        }

        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[A] = 0;
        pq.add(new Edge(A, 0));

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();

            if (dist[edge.to] < edge.weight) {
                continue;
            }

            for (int i = 0; i < edgeList.get(edge.to).size(); i++) {
                Edge e = edgeList.get(edge.to).get(i);

                if (dist[e.to] > edge.weight + e.weight) {
                    dist[e.to] = edge.weight + e.weight;
                    pq.offer(new Edge(e.to, dist[e.to]));
                }
            }
        }

        System.out.println(dist[B]);
    }
}
