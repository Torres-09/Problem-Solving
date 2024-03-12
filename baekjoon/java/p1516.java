package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1516 {
    static int N;
    static int[] count;
    static ArrayList<Integer>[] arr;
    static int[] time;
    static int[] answer;
    // 건물번호, 이전에 소요된 시간, 건물 짓는 데 필요한 건물 개수
    static PriorityQueue<int[]> pq;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visit = new boolean[N + 1];
        arr = new ArrayList[N + 1];
        time = new int[N + 1];
        answer = new int[N + 1];
        count = new int[N + 1];
        pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));

        for (int i = 0; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            time[i] = Integer.parseInt(s);

            s = st.nextToken();
            while (!s.equals("-1")) {
                arr[Integer.parseInt(s)].add(i);
                count[i]++;
                s = st.nextToken();
            }

            if (count[i] == 0) {
                pq.add(new int[]{i, count[i]});
            }
        }
        while (!pq.isEmpty()) {
            int[] building = pq.poll();
            int buildNum = building[0];
            if (visit[buildNum]) continue;
            visit[buildNum] = true;

            answer[buildNum] += time[buildNum];
            for (int i = 0; i < arr[buildNum].size(); i++) {
                count[arr[buildNum].get(i)]--;
                answer[arr[buildNum].get(i)] = Math.max(answer[buildNum], answer[arr[buildNum].get(i)]);
                pq.add(new int[]{arr[buildNum].get(i), count[arr[buildNum].get(i)]});
            }
        }

        for (int i = 1; i <= N; i++) {
            System.out.println(answer[i]);
        }
    }
}

// https://www.acmicpc.net/problem/1516