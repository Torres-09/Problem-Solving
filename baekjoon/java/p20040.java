package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p20040 {
    static int N, M;
    static int[] parents;
    static boolean answer;
    static int turn;

    static int find(int c) {
        if (parents[c] == c) {
            return c;
        }
        return parents[c] = find(parents[c]);
    }

    static boolean union(int a, int b) {
        int aRoot = find(Math.min(a, b));
        int bRoot = find(Math.max(a, b));

        if(aRoot == bRoot) return true;

        parents[aRoot] = bRoot;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parents = new int[N];

        for (int i = 0; i < N; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (union(a, b)) {
                answer = true;
                turn = i+1;
                break;
            }
        }

        if (answer) {
            System.out.println(turn);
        } else {
            System.out.println("0");
        }
    }
}
