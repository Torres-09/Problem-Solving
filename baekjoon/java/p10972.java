package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p10972 {
    static int N;
    static int[] arr;

    public static void swap(int left, int right) {
        // Swap the data
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    public static void reverse(int left, int right) {

        while (left < right) {
            int temp = arr[left];
            arr[left++] = arr[right];
            arr[right--] = temp;
        }
    }

    public static boolean findNextPermutation() {

        if (arr.length <= 1) return false;
        int last = arr.length - 2;
        while (last >= 0 && arr[last] >= arr[last+1]) last--;
        if (last < 0) return false;

        int nextGreater = arr.length - 1;
        while (arr[last] >= arr[nextGreater]) nextGreater--;

        swap(nextGreater, last);
        reverse(last + 1, arr.length - 1);
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

        if (findNextPermutation()) {
            for (int i : arr) {
                System.out.print(i + " ");
            }
        } else {
            System.out.println("-1");
        }
    }
}
