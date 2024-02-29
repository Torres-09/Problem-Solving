package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class p1946 {
    static int T, N;
    static int[][] score;
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            score = new int[N][2];
            answer = 1;
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                score[i][0] = Integer.parseInt(st.nextToken());
                score[i][1] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(score, (o1, o2) -> Integer.compare(o1[0], o2[0]));

            int top = score[0][1];
            for (int i = 1; i < N; i++) {
                if (score[i][1] < top) {
                    answer++;
                    top = score[i][1];
                }
            }

            System.out.println(answer);
        }
    }
}
