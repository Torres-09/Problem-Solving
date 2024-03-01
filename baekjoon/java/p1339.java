package com.baekjoon.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class p1339 {
	static int N;
	static ArrayList<String> list;
	static HashMap<Character, Integer> map;
	static ArrayList<Integer> answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		list = new ArrayList<>();
		map = new HashMap<>();
		answer = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			list.add(br.readLine());
		}

		for (String s : list) {
			for (int i = 0; i < s.length(); i++) {
				map.put(s.charAt(i), (int)(map.getOrDefault(s.charAt(i), 0) + Math.pow(10, s.length() - i - 1)));
			}
		}

		answer.addAll(map.values());
		answer.sort((o1, o2) -> Integer.compare(o2, o1));
		int sum = 0;
		int mul = 9;
		for (int i : answer) {
			sum += i * mul;
			mul--;
		}
		System.out.println(sum);
	}
}
