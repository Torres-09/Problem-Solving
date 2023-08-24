package com.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1759 {
    static int l, c;
    static char[] arr;
    static boolean[] aeiou;
    static char[] answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        answer = new char[l];
        arr = new char[c];
        aeiou = new boolean[c];
        for (int i = 0; i < c; i++) {
            arr[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(arr);
        for (int i = 0; i < c; i++) {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') aeiou[i] = true;
        }

        check(0, -1, 0, 0);
    }

    static void check(int pos, int prev, int conso_count, int vowel_count)
    {
        if (pos == l && conso_count >= 1 && vowel_count >= 2)
        {
            for (int i = 0; i < l; i++)
            {
                System.out.print(answer[i]);
            }
            System.out.println();
            return;
        }

        for (int i = prev + 1; i < c; i++)
        {
            char now = arr[i];
            answer[pos] = now;

            if (aeiou[i])
                check(pos + 1, i, conso_count + 1, vowel_count);
            else
                check(pos + 1, i, conso_count, vowel_count + 1);
        }
    }
}
