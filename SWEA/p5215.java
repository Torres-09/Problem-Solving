package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p5215 {
    static int t;
    static int n, l;
    static int answer;

    static int[] flavor;
    static int[] cal;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int q = 1; q <= t; q++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            answer = 0;
            flavor = new int[n];
            cal = new int[n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                flavor[i] = Integer.parseInt(st2.nextToken());
                cal[i] = Integer.parseInt(st2.nextToken());
            }

            makeSubSet(0,0,0);
            System.out.println("#" + q + " " + answer);
        }
    }

    static void makeSubSet(int cnt, int cc, int ff) {
        if (cc >= l) {
            return;
        }

        if (cnt == n) {
            answer = Math.max(answer, ff);
            return;
        }

        makeSubSet(cnt +1, cc + cal[cnt], ff + flavor[cnt]);
        makeSubSet(cnt + 1, cc, ff);
    }
}
