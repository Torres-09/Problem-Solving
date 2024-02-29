package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class p16935 {
    static long A, B;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        Queue<long[]> q = new ArrayDeque<>();
        q.add(new long[]{A, 1});
        while (!q.isEmpty()) {
            long now = q.peek()[0];
            long count = q.peek()[1];
            q.poll();

            if (now > B) {
                continue;
            }

            if (now == B) {
                System.out.println(count);
                return;
            }

            q.add(new long[]{now * 2, count + 1});
            q.add(new long[]{now * 10 + 1, count + 1});
        }

        System.out.println("-1");
    }
}
