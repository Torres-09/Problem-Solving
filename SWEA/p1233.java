package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p1233 {

    static int n;
    static Node[] nodes;
    static ArrayList<Node> nodeArrayList;

    static class Node {
        String data;
        int left;
        int right;

        public Node(String data, int left, int right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }

        public Node(String data) {
            this.data = data;
            left = 0;
            right = 0;
        }

        public Node() {
        }
    }

    static void travel(int node) {
        if (node > n) return;
        // 왼쪽
        travel(node * 2);
        // 본인 방문
        nodeArrayList.add(nodes[node]);
        // 오른쪽
        travel(node * 2 + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            n = Integer.valueOf(br.readLine());
            nodes = new Node[n + 1];
            nodeArrayList = new ArrayList<>();

            // tree 완성
            for (int i = 1; i <= n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                // internal Node
                if (st.countTokens() == 4)
                    nodes[Integer.parseInt(st.nextToken())] = new Node(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                    // Leaf Node
                else nodes[Integer.parseInt(st.nextToken())] = new Node(st.nextToken());
            }

            int answer = 1;
            for (int i = 1; i <= n; i++) {
                if (nodes[i].left == 0 && nodes[i].right == 0) {
                    try {
                        int a = Integer.parseInt(nodes[i].data);
                    } catch (Exception e) {
                        answer = 0;
                        break;
                    }
                }
            }
            System.out.println("#" + t + " " + answer);
        }
    }
}
