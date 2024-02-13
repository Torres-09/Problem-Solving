package com.sw.java;

import java.util.Arrays;
import java.util.Scanner;

public class p1208 {
    static int[] arr = new int[101];
    static int index = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = 10;
        while (t > 0) {
            int n = sc.nextInt();
            int answer = 0;
            for (int i = 0; i < 100; i++) {
                arr[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                Arrays.sort(arr);
                arr[0] += 1;
                arr[99] -= 1;
            }

            Arrays.sort(arr);

            answer = arr[99] - arr[0];

            System.out.println("#" + index++ + " " + answer);
            t--;
        }
    }
}
