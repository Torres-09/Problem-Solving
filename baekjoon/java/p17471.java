package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class p17471 {
    static int n;
    static int[] cityList;
    static boolean[][] graph;
    static boolean[] city;
    static boolean[] isVisit;
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        cityList = new int[n + 1];
        city = new boolean[n + 1];
        graph = new boolean[n + 1][n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            cityList[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int length = Integer.parseInt(st.nextToken());
            for (int j = 0; j < length; j++) {
                graph[i][Integer.parseInt(st.nextToken())] = true;
            }
        }

        // 최소 1개부터 n-1개까지 조합이 가능
        for (int i = 1; i < n; i++) {
            combination(1, 0, i);
        }

        System.out.println(answer != Integer.MAX_VALUE ? answer : -1);
    }

    static void combination(int start, int cnt, int k) {
        if (cnt == k) {
            answer = Math.min(answer, check());
            return;
        }

        for (int i = start; i <= n; i++) {
            city[i] = true;
            combination(i + 1, cnt + 1, k);
            city[i] = false;
        }
    }

    static int check() {
        // true 체크된 도시들, false 체크된 도시들 순회가 가능해야 한다.
        isVisit = new boolean[n + 1];
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);
        isVisit[1] = true;
        int result1 = 0;
        int result2 = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            result1 += cityList[cur];

            for (int i = 1; i <= n; i++) {
                if (graph[cur][i] && city[i] == city[1] && !isVisit[i]) {
                    isVisit[i] = true;
                    q.add(i);
                }
            }
        }

        int next = 0;
        for (int i = 2; i <= n; i++) {
            if (city[i] != city[1]) {
                next = i;
                break;
            }
        }
        q.add(next);
        isVisit[next] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            result2 += cityList[cur];

            for (int i = 1; i <= n; i++) {
                if (graph[cur][i] && city[i] == city[next] && !isVisit[i]) {
                    isVisit[i] = true;
                    q.add(i);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!isVisit[i]) return Integer.MAX_VALUE;
        }

        return Math.abs(result1 - result2);
    }
}
