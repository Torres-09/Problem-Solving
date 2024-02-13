package com.baekjoon.java;

import java.util.Scanner;

public class p1074 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        System.out.println(solve(n, r, c));
    }

    static int solve(int n, int r, int c) {
        if (n == 0) return 0;

        int half = (int) (Math.pow(2, n) / 2);

        if (r < half && c < half) return solve(n - 1, r % half, c % half);
        else if (r < half) return (int) (Math.pow(half, 2) * 1 + solve(n - 1, r, c % half));
        else if(c < half) return (int) (Math.pow(half, 2) * 2 + solve(n - 1, r % half, c));
        else return (int) (Math.pow(half, 2) * 3 + solve(n - 1, r, c));
    }
}
