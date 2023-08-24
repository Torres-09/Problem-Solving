package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p6987 {
    static int[][][] arr;
    static StringBuilder answer = new StringBuilder("");
    static boolean[][] Visit;
    static boolean check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new int[4][6][3];
        for (int i = 0; i < 4; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            Visit = new boolean[6][6];
            check = false;
            boolean start = false;
            for (int j = 0; j < 6; j++) {
                int temp = 0;
                for (int k = 0; k < 3; k++) {
                    temp += arr[i][j][k];
                }
                if (temp > 5) start = true;
            }
            if (!start) match(i, 0);


            if (check) answer.append("1 ");
            else answer.append("0 ");
        }

        System.out.println(answer);
    }

    static void match(int index, int cnt) {
        // 경기는 최대 15번 발생한다.
        if (cnt == 15) {
            check = true;
            return;
        }

        // team 1 ( 0부터 4까지 가능)
        for (int i = 0; i < 5; i++) {
            // team 2 ( 1부터 5까지 가능 )
            for (int j = i + 1; j < 6; j++) {
                if (i == j) continue;
                // 1팀과 2팀의 경기가 반드시 수행된다.
                boolean flag = false;
                for (int k = 0; k < 3; k++) {
                    // 경기가 남았다. 또한 두 팀은 경기를 아직 하지 않았다.
                    if (arr[index][i][k] > 0 && arr[index][j][2 - k] > 0 && !Visit[i][j] && !Visit[j][i]) {
                        flag = true;
                        // 이제 두 팀은 경기를 했다.
                        Visit[i][j] = true;
                        Visit[j][i] = true;
                        arr[index][i][k]--;
                        arr[index][j][2 - k]--;

                        // team1과 team2는 경기를 했다. 다음 반복에서는 team1은 team2 다음 팀과 경기를 치뤄야한다.
                        match(index, cnt + 1);

                        // 이제 두 팀은 경기를 안했다.
                        arr[index][i][k]++;
                        arr[index][j][2 - k]++;
                        Visit[i][j] = false;
                        Visit[j][i] = false;
                    }
                }
                if (!flag) return;
            }
        }
    }
}
