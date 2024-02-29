package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class p10610 {
    static String N;
    static int sum;
    static boolean flag;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = br.readLine();

        for (int i = 0; i < N.length(); i++) {
            if (N.charAt(i) - '0' == 0) {
                flag = true;
            }
            sum += N.charAt(i) - '0';
        }

        if (sum % 3 != 0 || !flag) {
            System.out.println("-1");
        } else {
            char[] chars = N.toCharArray();
            Arrays.sort(chars);
            for (int i = N.length() -1; i >= 0; i--) {
                System.out.print(chars[i]);
            }
        }
    }
}
