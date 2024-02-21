package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p10775 {
    static int N, M;
    static int[] parents;
    static int answer;

    static int find(int c) {
        if (parents[c] == c) return c;

        return parents[c] = find(parents[c]);
    }

    static void union(int a, int b) {
        int aRoot = find(Math.max(a, b));
        int bRoot = find(Math.min(a, b));

        if (aRoot == bRoot) return;

        parents[aRoot] = bRoot;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        parents = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int last = Integer.parseInt(br.readLine());
            if (find(last) == 0) {
                break;
            }

            answer++;
            union(find(last), find(last)-1);
        }

        System.out.println(answer);
    }
}
