package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p4012 {
    static int t;
    static int n;
    static int[][] arr = new int[17][17];

    static int[] gradient = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int q = 1; q <= t; q++) {
            n = Integer.parseInt(br.readLine());

            // 시너지 조합 완료
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // 1 ~ n 까지의 식재료

            // n가지 식재료 중 n/2개를 골라서 음식을 만든다. nCn/2
            // nCn/2의 식재료를 순열로 세워서 2개 씩 묶어서 음식에 넣는다.
        }
    }



    static boolean np(int[] number) {
        int i = n - 1;

        while (i > 0 && number[i - 1] >= number[i]) i--;

        if (i == 0) return false;

        int j = n - 1;
        while (number[i - 1] >= number[j]) j--;

        swap(number, i - 1, j);

        int k = n - 1;
        while (i < k) swap(number, i++, k--);

        return true;
    }

    static void swap(int[] number, int i, int j) {
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
}
