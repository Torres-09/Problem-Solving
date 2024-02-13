package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p15961 {
    /**
     * 초밥 접시 수, 초밥의 가짓 수, 연속해서 먹는 접시의 , 쿠폰 번호
     */
    static int n, d, k, c;
    static int[] arr;
    static int[] cntList;
    static int answer;
    static boolean isThere;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new int[n];
        cntList = new int[d + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if(arr[i] == c) isThere = true;
        }

        int left = 0;
        int right = 0;
        int size = 0;


        if(!isThere) answer++;
        System.out.println(answer);
    }
}
