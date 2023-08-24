package com.baekjoon;

import java.util.*;

public class p1260 {
    static ArrayList<Integer>[] graph;
    static Queue<Integer> q;
    static boolean[] visit;
    static int n, m, v;

    static void DFS(int start) {
        visit[start] = true;
        System.out.print(start + " ");

        for (int i = 0; i < graph[start].size(); i++) {
            int next = graph[start].get(i);
            if (!visit[next]) {
                DFS(next);
            }
        }
    }

    static void BFS(int start) {
        visit[start] = true;
        q.add(start);
        System.out.print(start + " ");

        while (!q.isEmpty()) {
            start = q.poll();
            for (int i = 0; i < graph[start].size(); i++) {
                int next = graph[start].get(i);
                if (!visit[next]) {
                    q.add(next);
                    System.out.print(next + " ");
                    visit[next] = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();

        graph = new ArrayList[n + 1];
        visit = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            visit[i] = false;
        }

        int start, end;
        for (int i = 0; i < m; i++) {
            start = sc.nextInt();
            end = sc.nextInt();
            graph[start].add(end);
            graph[end].add(start);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(graph[i]);
        }

        q = new LinkedList<>();
        DFS(v);
        System.out.println();

        Arrays.fill(visit, false);
        BFS(v);
    }
}
