package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1439 {
    static String arr;
    static int countZero;
    static int countOne;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = br.readLine();

        for (int i = 0; i < arr.length(); i++) {
            if (arr.charAt(i) == '1') {
                int start = i;
                countZero++;
                for (int j = i; j < arr.length(); j++) {
                    if (arr.charAt(start) != arr.charAt(j)) break;

                    i++;
                }
            }
        }
        for (int i = 0; i < arr.length(); i++) {
            if (arr.charAt(i) == '0') {
                int start = i;
                countOne++;
                for (int j = i; j < arr.length(); j++) {
                    if (arr.charAt(start) != arr.charAt(j)) break;

                    i++;
                }
            }
        }

        System.out.println(Math.min(countZero, countOne));
    }
}

// https://www.acmicpc.net/problem/1439