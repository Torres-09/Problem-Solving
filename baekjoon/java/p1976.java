package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p1976 {
    static int N, M;
    static int[] arr;
    static boolean answer;

    static int find(int c) {
        if (arr[c] == c) return c;
        else return arr[c] = find(arr[c]);
    }

    static void union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot == bRoot) return;

        arr[bRoot] = aRoot;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        answer = false;
        for (int i = 0; i <= N; i++) {
            arr[i] = i;
        }

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (st.nextToken().equals("1")) {
                    union(i, j);
                }
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int source = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M - 1; i++) {
            int destination = Integer.parseInt(st.nextToken());
            if (find(source) != find(destination)) answer = true;
        }

        if (answer) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}

