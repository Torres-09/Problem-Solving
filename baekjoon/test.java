package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
    static int ans = 0;
    static int func(int n,int r, int c) {
        if(n == 0) return 0;
        return 2*(r%2) + (c%2) + 4*func(n-1,r/2,c/2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]), r = Integer.parseInt(s[1]), c = Integer.parseInt(s[2]);
        System.out.println(func(n,r,c));
    }

}
