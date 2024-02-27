package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p10973 {
    static int N;
    static int[] arr;

    static void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static void reverse(int first, int last) {
        while (first <= last) {
            swap(first, last);
            first++;
            last--;
        }
    }

    static boolean findPrevPermutation() {
        if (arr.length <= 1) return false;
        int last = arr.length - 2;
        while (last >= 0 && arr[last] <= arr[last + 1]) last--;
        if (last < 0) return false;

        int nextGreater = arr.length - 1;
        while (arr[last] <= arr[nextGreater]) nextGreater--;

        swap(last, nextGreater);
        reverse(last + 1, arr.length - 1);
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        if (findPrevPermutation()) {
            for (int i : arr) {
                System.out.print(i + " ");
            }
        } else {
            System.out.println("-1");
        }
    }
}
