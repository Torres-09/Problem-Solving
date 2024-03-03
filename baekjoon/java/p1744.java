package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class p1744 {
	static ArrayList<Integer> plus;
	static ArrayList<Integer> minus;
	static ArrayList<Integer> zero;
	static int N;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		plus = new ArrayList<>();
		minus = new ArrayList<>();
		zero = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			if (num < 0) {
				minus.add(num);
			} else if (num == 0) {
				zero.add(num);
			} else {
				plus.add(num);
			}
		}
		plus.sort((o1, o2) -> Integer.compare(o2, o1));
		minus.sort(Integer::compare);

		for (int i = 0; i < (plus.size() / 2) * 2; i += 2) {
			int first = plus.get(i);
			int second = plus.get(i + 1);
			if (first * second <= first + second) {
				answer += first + second;
			} else {
				answer += first * second;
			}
		}
		for (int i = 0; i < (minus.size() / 2) * 2; i += 2) {
			int first = minus.get(i);
			int second = minus.get(i + 1);
			answer += first * second;
		}
		// 마이너스 개수가 남는다면?
		if (minus.size() % 2 != 0) {
			// 0이 있다면?
			if (!zero.isEmpty()) {
				answer += 0;
			} else {
				answer += minus.get(minus.size() - 1);
			}
		}
		if (plus.size() % 2 != 0) {
			answer += plus.get(plus.size() - 1);
		}
		System.out.println(answer);
	}
}
