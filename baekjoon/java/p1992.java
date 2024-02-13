package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p1992 {
    static char[][] v;

    public static void solution(int x, int y, int size) {
        if (size == 1) {
            System.out.print(v[x][y]);
            return;
        }

        char check = v[x][y];

        for (int j = y; j < y + size; j++) {
            for (int i = x; i < x + size; i++) {
                if (check != v[i][j]) {
                    System.out.print("(");
                    solution(x, y, size / 2);
                    solution(x, y + size / 2, size / 2);
                    solution(x + size / 2, y, size / 2);
                    solution(x + size / 2, y + size / 2, size / 2);
                    System.out.print(")");
                    return;
                }
            }
        }
        System.out.print(check);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        v = new char[n][n];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                v[i][j] = s.charAt(j);
            }
        }

        solution(0, 0, n);
    }
}
