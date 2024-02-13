package com.baekjoon.java;

import java.awt.*;
import java.util.ArrayList;
import java.util.Scanner;

public class p15686 {
    static int n, m;
    static int[][] map = new int[51][51];
    static boolean[] Visit = new boolean[15];
    static ArrayList<Pair> chicken = new ArrayList<>();
    static ArrayList<Pair> house = new ArrayList<>();
    static int answer;

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.x = y;
        }
    }

    static void Check(int num, int index) {
        if (num == m) {
            int sum = 0;
            // 치킨거리 계산 로직
            for (int i = 0; i < house.size(); i++) {
                int x = house.get(i).x;
                int y = house.get(i).y;
                int temp = Integer.MAX_VALUE;
                for (int j = 0; j < chicken.size(); j++) {
                    if (Visit[j]) {
                        int x1 = chicken.get(j).x;
                        int y1 = chicken.get(j).y;
                        temp = Math.min(temp, Math.abs(x - x1) + Math.abs(y - y1));
                    }
                }
                sum += temp;
            }
            answer = Math.min(answer, sum);
            return;
        }

        for (int i = index; i < chicken.size(); i++) {
            if (Visit[i]) continue;

            Visit[i] = true;
            Check(num + 1, i + 1);
            Visit[i] = false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        answer = Integer.MAX_VALUE;

        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = scanner.nextInt();

                if (map[i][j] == 2) chicken.add(new Pair(i, j));
                if (map[i][j] == 1) house.add(new Pair(i, j));
            }
        }

        Check(0, 0);
        System.out.println(answer);
    }
}
