package com.baekjoon.java;

import java.util.Scanner;

public class p11659 {
    static int n, m;
    static int arr[];
    static int sum[];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n+2];
        sum = new int[n+2];
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
            sum[i] += sum[i-1] + arr[i];
        }


        for (int i = 0; i < m; i++) {
            int left,right;
            left = sc.nextInt();
            right = sc.nextInt();
            System.out.println(sum[right] - sum[left-1]);
        }
    }
}
