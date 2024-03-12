package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1238 {
    static class Node{
        int vertex;
        int cost;
        Node next;

        Node(int vertex, int cost, Node next) {
            this.vertex = vertex;
            this.cost = cost;
            this.next = next;
        }
    }

    static int N,M, X;
    static Node[] adjList;
    static Node[] reverseAdjList;
    static int[] dist;
    static int[] reverseDist;
    static int answer;

    static int[] dijkstra(Node[] adjList, int[] dist) {
        dist = new int[N + 1];
        Arrays.fill(dist, 100_000_000);
        dist[X] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(o1->o1.cost));
        pq.add(new Node(X, 0, null));

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            int nowVertex = now.vertex;

            for (Node temp = adjList[nowVertex]; temp != null; temp = temp.next) {
                int nextVertex = temp.vertex;
                int cost = temp.cost;

                if (dist[nextVertex] > dist[nowVertex] + cost) {
                    dist[nextVertex] = dist[nowVertex] + cost;
                    pq.add(new Node(nextVertex, dist[nextVertex], null));
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
        adjList = new Node[N + 1];
        reverseAdjList = new Node[N + 1];
        dist = new int[N + 1];
        reverseDist = new int[N + 1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adjList[start] = new Node(end, cost, adjList[start]);
            reverseAdjList[end] = new Node(start, cost, reverseAdjList[end]);
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