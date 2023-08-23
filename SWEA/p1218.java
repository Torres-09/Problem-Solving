package com.sw;

import java.util.Scanner;
import java.util.Stack;

public class p1218 {
    static int n;
    static Stack<Character> stack;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 1; i <= 10; i++) {
            int answer = 0;
            n = sc.nextInt();
            String str = sc.next();
            stack = new Stack<>();

            stack.push(str.charAt(0));
            for (int j = 1; j < n; j++) {
                char newChar = str.charAt(j);
                if (!stack.empty()) {
                    if ((newChar == '(' && stack.peek() == ')')
                    || (newChar == '{' && stack.peek() =='}'
                    || (newChar == '[' && stack.peek() == ']')
                    || (newChar == '<' && stack.peek() == '>')
                    || (stack.peek() == '[' && newChar == ']')
                    || (stack.peek() == '{' && newChar == '}')
                    || (stack.peek() == '(' && newChar == ')')
                    || (stack.peek() == '<' && newChar == '>')
                    )) {
                        stack.pop();
                        continue;
                    }
                }
                stack.push(newChar);
            }

            // 스택이 비어있으면 -> 짝이 맞으면
            if (stack.empty()) {
                answer = 1;
            } else {
                answer = 0;
            }

            System.out.println("#" + i + " " + answer);
        }
    }
}
