package com.baekjoon.java;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class p2961 {
    static int N;
    static int S[], B[];
    static boolean isSelected[];
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        S = new int[N];
        B = new int[N];
        isSelected = new boolean[N];
        // S는 곱
        // B는 합
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
            B[i] = sc.nextInt();
        }

        generateSubSet(0);
        System.out.println(answer);
    }

    static void generateSubSet(int cnt) {
        if (cnt == N) {
            answer = Math.min(answer, cal());
            return;
        }

        isSelected[cnt] = true;
        generateSubSet(cnt + 1);
        isSelected[cnt] = false;
        generateSubSet(cnt + 1);
    }

    static int cal() {
        boolean flag = false;

        int s = 1;
        int b = 0;
        for (int i = 0; i < N; i++) {
            if (isSelected[i]) {
                flag = true;
                s *= S[i];
                b += B[i];
            }
        }

        if(!flag) return Integer.MAX_VALUE;

        return Math.abs(s - b);
    }
}
