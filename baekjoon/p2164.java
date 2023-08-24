package com.baekjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*
 * 1. summary:
 *
 * 2. strategy: 풀이전략
 *
 * 3. note: 주의할 사항(특이사항)

 */

public class p2164 {
    static int n;
    static Queue<Integer> queue = new LinkedList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }

        while (true) {
            // 버린다
            queue.poll();

            // 카드 위치 변
            queue.add(queue.poll());
            if (queue.size() == 1) {
                break;
            }
        }

        System.out.println(queue.peek());
    }
}
