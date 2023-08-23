package com.sw;

import java.util.Scanner;

public class p0731 {
    static int t;
    static String s1;
    static String s0;
    static int index = 1;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();

        for (int i = 0; i <= 50; i++) {
            s1 += "1";
            s0 += "0";
        }

        while (t > 0) {
            String s = sc.next();
            int result = 0;
            boolean flag = false;
            for (int i = 0; i < s.length(); i++) {
                // 0인 상태
                if (flag == false) {
                    if (s.charAt(i) != '0'){
                        flag = !flag;
                        result++;
                    }
                } else {
                    if (s.charAt(i) != '1') {
                        flag = !flag;
                        result++;
                    }
                }
            }


            t--;
            System.out.println("#" + index++ + " " + result);
        }
    }
}
