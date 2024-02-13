package com.baekjoon.java;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class p12891 {
    static int s, p;
    static String str;
    static Map<Character, Integer> map = new HashMap<>();
    static Map<Character, Integer> checkMap = new HashMap<>();
    static int answer;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextInt();
        p = sc.nextInt();
        str = sc.next();
        map.put('A', sc.nextInt());
        map.put('C', sc.nextInt());
        map.put('G', sc.nextInt());
        map.put('T', sc.nextInt());
        checkMap.put('A', 0);
        checkMap.put('C', 0);
        checkMap.put('T', 0);
        checkMap.put('G', 0);

        int start = 0;
        int end = start + p;
        String substring = str.substring(start, end);
        // 첫 부분 문자열 check
        for (int i = 0; i < substring.length(); i++) {
            checkMap.put(substring.charAt(i), checkMap.get(substring.charAt(i)) + 1);
        }
        if (checkMap.get('A') >= map.get('A') && checkMap.get('C') >= map.get('C') &&
                checkMap.get('T') >= map.get('T') && checkMap.get('G') >= map.get('G')) {
            answer++;
        }

        start++;
        end++;
        while (end <= str.length()) {
            checkMap.put(str.charAt(start - 1), checkMap.get(str.charAt(start - 1)) - 1);
            checkMap.put(str.charAt(end-1), checkMap.get(str.charAt(end-1)) + 1);

            if (checkMap.get('A') >= map.get('A') && checkMap.get('C') >= map.get('C') &&
                    checkMap.get('T') >= map.get('T') && checkMap.get('G') >= map.get('G')) {
                answer++;
            }

            start++;
            end++;
        }

        System.out.println(answer);
    }
}
