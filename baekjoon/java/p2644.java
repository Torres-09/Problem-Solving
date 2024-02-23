package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p2644 {
    static int n;
    static int a, b, m;
    static ArrayList<Integer>[] graph;
    static int[] parent;
    static boolean[] visit;
    static int answer;

    static void DFS(int x, int cnt) {
        visit[x] = true;
        if (x == b) {
            if (answer != 0) {
                answer = Math.min(answer, cnt);
            } else {
                answer = cnt;
            }
            return;
        }

        if (!visit[parent[x]]) {
            DFS(parent[x], cnt + 1);
        }

        for (int i = 0; i < graph[x].size(); i++) {
            int child = graph[x].get(i);
            if (visit[child]) continue;

            DFS(child, cnt + 1);
        }
        visit[x] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(br.readLine());
        graph = new ArrayList[n + 1];
        visit = new boolean[n + 1];
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            parent[y] = x;
            graph[x].add(y);
        }

        DFS(a, 0);
        System.out.println(answer == 0 ? -1 : answer);
    }
}
