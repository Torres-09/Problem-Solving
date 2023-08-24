package com.baekjoon;

import java.util.Arrays;
import java.util.Scanner;

public class p15649 {
    static int n, m;
    static int[] arr;
    static boolean[] Visit;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[m];
        Visit = new boolean[n+1];

        solve(0);
    }

    static void solve(int cnt) {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " "   );
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
            if(Visit[i])  continue;
            Visit[i] = true;
            arr[cnt] = i;
            solve(cnt + 1);
            Visit[i] = false;
        }
    }
}
