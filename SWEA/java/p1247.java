package com.sw.java;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p1247 {
    static int t, n;
    static boolean[] isSelected;
    static int answer;
    static Point company, house;
    static ArrayList<Point> customer;
    static int distance;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int a = 1; a <= t; a++) {
            n = Integer.parseInt(br.readLine());
            isSelected = new boolean[n];
            answer = Integer.MAX_VALUE;
            distance = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            // 회사, 집, 고객
            company = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            house = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            customer = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                customer.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
            }

            // 회사에서 출발 -> 고객을 모두 거치고 -> 집으로 간다.
            travel(0, company.x, company.y);
            System.out.println("#" + a + " " + answer);
        }
    }

    static void travel(int cnt, int curX, int curY) {
        // 모든 고객을 방문했다. 집에 드가자
        if (cnt == n) {
            distance += Math.abs(curX - house.x) + Math.abs(curY - house.y);
            answer = Math.min(answer, distance);
            distance -= Math.abs(curX - house.x) + Math.abs(curY - house.y);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSelected[i]) continue;
            isSelected[i] = true;
            distance += Math.abs(curX - customer.get(i).x) + Math.abs(curY - customer.get(i).y);
            travel(cnt + 1, customer.get(i).x, customer.get(i).y);
            isSelected[i] = false;
            distance -= Math.abs(curX - customer.get(i).x) + Math.abs(curY - customer.get(i).y);
        }
    }
}
