package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p10972 {
    static int N;
    static int[] arr;

    static boolean nextPermutation() {
        int i = N - 1;

        while (i > 0 && arr[i - 1] >= arr[i]) {
            i--;
        }

        if(i<=0) return false;

        int j = N - 1;

        while (arr[i - 1] >= arr[j]) {
            j--;
        }

        int temp = arr[j];
        arr[j] = arr[i - 1];
        arr[i - 1] = temp;
        j = N - 1;

        while (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if (nextPermutation()) {
            for (int i : arr) {
                System.out.print(i + " ");
            }
        } else {
            System.out.println("-1");
        }

    }
}
