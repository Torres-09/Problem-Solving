package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p3124 {
    static class Edge implements Comparable<Edge> {
        int from, to, weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static void make() {
        parent = new int[V+1];
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }

    static int find(int a) {
        if(parent[a] ==a) return a;
        return parent[a] = find(parent[a]);
    }

    static boolean union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        if(aRoot == bRoot) return false; // 사이클이 발생하는 경우이다.
        parent[bRoot] = aRoot;
        return true;
    }


    static int[] parent;

    static Edge[] edgeList;
    static int V, E;
    static int t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        t = Integer.parseInt(br.readLine());

        for (int q = 1; q <= t; q++) {
            st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            edgeList = new Edge[E];

            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                edgeList[i] = new Edge(from, to, weight);
            }

            Arrays.sort(edgeList);

            make();

            // 간선 전체의 가중치 합, 간선 선택 횟수 ( V-1이 되면 종료한다. )
            long result = 0;
            int count = 0;

            // 모든 간선에 대하여 사이클이 없다면 간선을 선택하여 집합을 합친다.
            for (Edge edge : edgeList) {
                if (union(edge.from, edge.to)) {
                    result += edge.weight;
                    if(++count == V-1) break;
                }
            }
            System.out.println("#" + q + " " + result);
        }
    }
}
