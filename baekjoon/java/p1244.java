package com.baekjoon.java;

import java.io.BufferedInputStream;
import java.io.InputStream;
import java.util.Scanner;

public class p1244 {
    static int n;
    static int arr[] = new int[102];
    static int pc;
    static int gender[] = new int[102];
    static int swit[] = new int[102];

    public static void main(String[] args) {
//        BufferedInputStream bufferedInputStream = new BufferedInputStream(System.in);
        Scanner sc = new Scanner(System.in);

        // 스위치 개수
        n = sc.nextInt();

        // 각 스위치 상태 입력
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }

        // 학생 수
        pc = sc.nextInt();

        // 학생 성별, 스위치 위치
        for (int i = 1; i <= pc; i++) {
            gender[i] = sc.nextInt();
            swit[i] = sc.nextInt();
        }

        // 확인
        for (int i = 1; i <= pc; i++) {
            // 남학생이라면
            if (gender[i] == 1) {
                for (int j = 1; j * swit[i] <= n; j++) {
                    if (arr[j * swit[i]] == 1) {
                        arr[j * swit[i]] = 0;
                    } else {
                        arr[j * swit[i]] = 1;
                    }
                }
            }
            // 여학생이라면
            else {
                if (arr[swit[i]] == 1) {
                    arr[swit[i]] = 0;
                } else {
                    arr[swit[i]] = 1;
                }
                // 대칭이 되는 구간까지 모두 0 1 교체
                int left = swit[i] - 1;
                int right = swit[i] + 1;
                while (left >= 1 && right <= n) {
                    if(arr[left] != arr[right]) break;

                    if (arr[left] == 1) {
                        arr[left] = 0;
                        arr[right] = 0;
                    } else {
                        arr[left] = 1;
                        arr[right] = 1;
                    }

                    left--;
                    right++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i == n) {
                System.out.print(arr[i]);
                continue;
            }
            if (i % 20 == 0) {
                System.out.print(arr[i]);
                System.out.println();
                continue;
            }
            System.out.print(arr[i] + " ");
        }
    }
}

// https://www.acmicpc.net/problem/1244