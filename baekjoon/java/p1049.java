package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1049 {
    static int N, M;
    static int[] pack;
    static int[] per;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        pack = new int[M];
        per = new int[M];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            pack[i] = Integer.parseInt(st.nextToken());
            per[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(pack);
        Arrays.sort(per);

        int answer = 0;
        if (per[0] * 6 <= pack[0]) {
            answer += per[0] * N;
        } else if (pack[0] * (N / 6 + 1) <= pack[0] * (N / 6) + per[0] * (N % 6)) {
            answer += pack[0] * (N / 6 + 1);
        } else {
            answer += (N / 6) * pack[0];
            answer += (N % 6) * per[0];
        }

        System.out.println(answer);
    }
}
