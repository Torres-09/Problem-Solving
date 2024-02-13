package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p10971 {
    static int n;
    static int[][] graph;
    static int[] arr;
    static long answer;
    static boolean[] isSelected;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        graph = new int[n + 1][n + 1];
        arr = new int[n + 1];
        answer = Long.MAX_VALUE;
        isSelected = new boolean[n + 1];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 0) graph[i][j] = Integer.MAX_VALUE;
            }
        }

        // 출발부터 도착까지
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                isSelected[i] = true;
                isSelected[j] = true;
                arr[0] = i;
                arr[n - 1] = j;
                permutation(1);
                isSelected[i] = false;
                isSelected[j] = false;
            }
        }

        System.out.println(answer);
    }

    static void permutation(int cnt) {
        if (cnt == n - 1) {
            long temp = 0;
            for (int i = 0; i < n - 1; i++) {
                temp += graph[arr[i]][arr[i + 1]];
            }
            answer = Math.min(answer, temp + graph[arr[n-1]][arr[0]]);

            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSelected[i]) continue;

            isSelected[i] = true;
            arr[cnt] = i;
            permutation(cnt + 1);
            isSelected[i] = false;
        }
    }
}
