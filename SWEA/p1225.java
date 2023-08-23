package com.sw;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p1225 {
    static Queue<Integer> queue;
    static int t;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 1; i <= 10; i++) {
            t = sc.nextInt();
            queue = new LinkedList<>();
            int cnt = 1;

            // 배열 입력
            for (int j = 0; j < 8; j++) {
                queue.add(sc.nextInt());
            }


            while (true) {
                int num = queue.poll();
                num -= cnt;
                if (num <= 0) {
                    num = 0;
                    queue.add(num);
                    break;
                } else {
                    queue.add(num);
                }
                cnt++;
                if(cnt == 6) cnt = 1;
            }

            System.out.print("#" + i + " ");
            for (int j = 0; j < 8; j++) {
                System.out.print(queue.poll() + " ");
            }
            System.out.println();
        }
    }
}
