package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class p2493 {
    static int n;
    static int arr[] = new int[500001];
    // 값, 순서
    static Map<Integer, Integer> map = new HashMap<>();
    static Stack<Integer> stack = new Stack<>();
    static Stack<Integer> temp = new Stack<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 탑 높이 초기 입력 받기
        for (int i = 1; i <= n; i++) {
            stack.push(Integer.valueOf(st.nextToken()));
            map.put(stack.peek(), i);
        }

        // 탑의 맨 끝부터 순회
        while (!stack.empty()) {
            // 아직 높은 탑을 못 만난 친구들
            while (!temp.empty()) {
                // 본인보다 높은 탑을 만났다면?
                if (temp.peek() < stack.peek()) {
                    arr[map.get(temp.pop())] = stack.size();
                } else {
                    break;
                }
            }

            temp.push(stack.pop());
        }

        // temp안에 친구들이 높은 탑을 못 만남
        while (!temp.empty()) {
            arr[map.get(temp.pop())] = 0;
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
