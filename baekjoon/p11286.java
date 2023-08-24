package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class p11286 {
    static int n;
    static PriorityQueue<Integer> priorityQueue = new PriorityQueue<>((o1, o2) -> Math.abs(o1) == Math.abs(o2) ?
            (o1 < o2 ? o1 : o2) : (Math.abs(o1) < Math.abs(o2)) ? o1 : o2
    );

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            if (num != 0) {
                priorityQueue.add(num);
            } else {
                if (priorityQueue.isEmpty()) {
                    System.out.println(0);
                    continue;
                }
                System.out.println(priorityQueue.poll());
            }
        }
    }
}
