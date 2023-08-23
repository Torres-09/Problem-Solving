package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p6808 {
    static int t;
    static boolean[] arr = new boolean[19];
    static int[] gyu = new int[9];
    static int[] in = new int[9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            arr = new boolean[19];
            gyu = new int[9];
            in = new int[9];

            StringTokenizer st = new StringTokenizer(br.readLine());

            // 규영이의 카드 뭉치
            for (int j = 0; j < 9; j++) {
                int num = Integer.parseInt(st.nextToken());
                arr[num] = true;
                gyu[j] = num;
            }
            // 인영이의 카드 뭉치를 오름차순으로 삽입
            int index = 0;
            for (int j = 1; j <= 18; j++) {
                if (!arr[j]) {
                    in[index++] = j;
                }
            }

            // 인영이의 카드 뭉치를 순열로 돌린다
            int victory = 0;
            int defeat = 0;
            do {
                int win = 0;
                int lose = 0;

                // 승점 계산
                for (int j = 0; j < 9; j++) {
                    if (gyu[j] > in[j]) win += gyu[j] + in[j];
                    else if (gyu[j] < in[j]) lose += gyu[j] + in[j];
                }

                // 승점이 더 높으면
                if (win > lose) victory++;
                // 승점이 더 낮으면
                if (lose > win) defeat++;

                // 내림 차순이 되면 false 반환할 것
            } while (np(in));

            System.out.println("#" + i + " " + victory + " " + defeat);
        }
    }

    static boolean np(int[] number) {
        int i = 8;

        while (i > 0 && number[i - 1] >= number[i]) i--;

        if (i == 0) return false;

        int j = 8;
        while (number[i - 1] >= number[j]) j--;

        swap(number, i - 1, j);

        int k = 8;
        while (i < k) swap(number, i++, k--);

        return true;
    }

    static void swap(int[] number, int i, int j) {
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
}
