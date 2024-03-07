package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p11779 {
    static int N, M;
    static int start, end;
    static ArrayList<Node>[] adjList;
    static int[] dist;
    static PriorityQueue<Node> pq;
    static boolean[] visit;
    static int[] prev;
    static ArrayList<Integer> path;

    static class Node {
        int vertex, cost;

        Node(int vertex, int cost) {
            this.vertex = vertex;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        adjList = new ArrayList[N+1];
        dist = new int[N + 1];
        visit = new boolean[N + 1];
        Arrays.fill(dist, 1000000000);
        pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.cost));
        prev = new int[N+1];
        path = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjList[start].add(new Node(end, cost));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        pq.add(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            int nowVertex = now.vertex;
            if(visit[nowVertex]) continue;
            visit[nowVertex] = true;
            if(nowVertex == end) break;

            for (int i = 0; i < adjList[nowVertex].size(); i++) {
                Node next = adjList[nowVertex].get(i);
                int nextVertex = next.vertex;
                int nextCost = next.cost;
                if (dist[nextVertex] > dist[nowVertex] + nextCost) {
                    dist[nextVertex] = dist[nowVertex] + nextCost;
                    pq.add(new Node(nextVertex, dist[nextVertex]));
                    prev[nextVertex] = nowVertex;
                }
            }
        }

        int index = end;
        while (index != 0) {
            path.add(index);
            index = prev[index];
        }

        System.out.println(dist[end]);
        System.out.println(path.size());
        for (int i = path.size() - 1; i >= 0; i--) {
            System.out.print(path.get(i) + " ");
        }
    }
}
