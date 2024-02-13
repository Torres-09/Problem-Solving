package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p2252 {
    static int deg[] = new int[32001];
    static ArrayList<Integer>[] v = new ArrayList[32001];
    static Queue<Integer> q = new ArrayDeque<>();
    static int n, m;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            v[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            v[a].add(b);
            deg[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.add(i);
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur + " ");
            for (int i : v[cur]) {
                deg[i]--;
                if (deg[i] == 0) q.add(i);
            }
        }

        System.out.println(sb);
    }
}
