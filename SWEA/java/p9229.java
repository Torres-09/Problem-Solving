package com.sw.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p9229 {
    static int t;
    static int n,m;
    static int arr[] = new int[1001];
    static int answer;

    static void combination(int start, int cnt, int w) {
        if (w > m) {
            return;
        }
        if (cnt == 2) {
            answer = Math.max(answer, w);
            return;
        }

        for (int i = start; i < n; i++) {
            combination(i + 1, cnt + 1, w + arr[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            answer = -1;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(st2.nextToken());
            }
            combination(0, 0, 0);

            System.out.println("#" + t + " " + answer);
        }
    }
}
