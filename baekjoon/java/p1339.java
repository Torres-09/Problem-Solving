package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class p1339 {
    static int N;
    static ArrayList<String> list;
    static HashMap<Character, Integer> map;
    static int num;
    static int[] answer;
    static ArrayList<int[]> place;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        map = new HashMap<>();
        num = 9;
        answer = new int[N];
        place = new ArrayList<>();
        // { A, 1 }
        // {
        int index = 0;
        for (int i = 0; i < N; i++) {
            list.add(br.readLine());
        }

        for (int i = 0; i < list.size(); i++) {
            String s = list.get(i);
            for (int j = 0; j < s.length(); j++) {
                place.add(new int[]{s.charAt(j), s.length() - j});
            }
        }

        place.sort((o1, o2) -> Integer.compare(o2[1], o1[1]));

        for (int i = 0; i < place.size(); i++) {
            int alphaNum = place.get(i)[0];
            if(!map.containsKey((char)alphaNum)) map.put((char) alphaNum, num--);
        }

        for (String s : list) {
            int plus = 0;
            for (int i = 0; i < s.length(); i++) {
                plus *= 10;
                plus += map.get(s.charAt(i));
            }
            answer[index++] = plus;
        }
        int sum = 0;
        for (int i : answer) {
            sum += i;
        }
        System.out.println(sum);
    }
}
