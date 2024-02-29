package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p2720 {
    static int T;
    static int C;
    static int a,b,c, d;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            C = Integer.parseInt(br.readLine());
            a = C / 25;
            C %= 25;
            b = C / 10;
            C %= 10;
            c = C / 5;
            C %= 5;
            d = C;

            System.out.println(a + " " + b + " " + c + " " + d);
        }
    }
}
