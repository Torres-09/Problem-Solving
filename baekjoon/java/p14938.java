package com.baekjoon.java;

import java.util.*;
import java.io.*;

public class p14938 {

    static int n,m, r;
    static int[] items;

    static int[][] graph;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        items = new int[n+1];
        graph = new int[n + 1][n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            items[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                graph[i][j] = 30000;
            }
        }

        for (int i = 0; i <= n; i++) graph[i][i] = 0;

        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[a][b] = cost;
            graph[b][a] = cost;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int temp = 0;
            for (int j = 1; j <= n; j++) {
                if(graph[i][j] <= m) temp += items[j];
            }
            answer = Math.max(answer, temp);
        }

        System.out.println(answer);
    }
}
