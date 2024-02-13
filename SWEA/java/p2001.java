package com.sw.java;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class p2001 {
    static int t,n, m;
    static int arr[][];
    public static void main(String[] args) {

        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int answer = 0;
            n = sc.nextInt();
            m = sc.nextInt();
            arr = new int[n][n];

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    arr[j][k] = sc.nextInt();
                }
            }

            for (int j = 0; j < n; j++) {
                if(j + m > n) break;
                for (int k = 0; k < n; k++) {
                    if(k+m>n) break;
                    answer = Math.max(answer, cal(j, k, m));
                }
            }

            System.out.println("#" + i + " " + answer);
        }
    }

    static int cal(int x, int y, int size) {
        int sum = 0;
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                sum += arr[i][j];
            }
        }
        return sum;
    }
}
