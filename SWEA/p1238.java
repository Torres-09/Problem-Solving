package com.sw;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p1238 {
    static int n, start;
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] isVisit;
    static Point answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for (int t = 1; t <= 10; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(st.nextToken());
            graph = new ArrayList<>();
            for (int i = 0; i <= 101; i++) {
                graph.add(new ArrayList<>());
            }
            isVisit = new boolean[101];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n / 2; i++) {
                graph.get(Integer.parseInt(st.nextToken())).add(Integer.parseInt(st.nextToken()));
            }

            Queue<Point> q = new ArrayDeque<>();
            // 방문 정점, 시간
            q.add(new Point(start, 0));
            isVisit[start] = true;
            answer = new Point(start, 0);

            while (!q.isEmpty()) {
                Point point = q.poll();
                int cur = point.x;
                int time = point.y;
                if (time > answer.y) {
                    answer.setLocation(point);
                } else if (time == answer.y) {
                    if (cur > answer.x) {
                        answer.setLocation(point);
                    }
                }

                for (int i = 0; i < graph.get(cur).size(); i++) {
                    if(isVisit[graph.get(cur).get(i)]) continue;

                    isVisit[graph.get(cur).get(i)] = true;
                    q.add(new Point(graph.get(cur).get(i), time + 1));
                }
            }

            System.out.println("#" + t + " " + answer.x);
        }
    }
}
