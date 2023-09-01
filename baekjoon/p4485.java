package com.baekjoon;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p4485 {
    static int n;
    static int[][] board;

    // 각 정점마다 4가지 간선을 갖는다.
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static class Node implements Comparable<Node> {
        Point to;
        int weight;

        public Node(Point to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static ArrayList<ArrayList<Node>> nodeList;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = 1;
        while (true) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            board = new int[n][n];
            nodeList = new ArrayList<>();
            dist = new int[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    nodeList.add(new ArrayList<>());
                    board[i][j] = Integer.parseInt(st.nextToken());
                    dist[i][j] = Integer.MAX_VALUE;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        // 벽을 넘어버림
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        nodeList.get(i * n + j).add(new Node(new Point(nx, ny), board[nx][ny]));
                    }
                }
            }

            // (0,0)에서 시작해서 (n-1,n-1) 로 간다
            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.offer(new Node(new Point(0, 0), 0));
            dist[0][0] = board[0][0];

            while (!pq.isEmpty()) {
                Node cur = pq.poll();
                Point curPoint = cur.to;

                if (dist[curPoint.x][curPoint.y] < cur.weight) continue;

                for (int i = 0; i < nodeList.get(curPoint.x * n + curPoint.y).size(); i++) {
                    Node next = nodeList.get(curPoint.x * n + curPoint.y).get(i);
                    Point nextCur = next.to;
                    if (dist[nextCur.x][nextCur.y] <= dist[curPoint.x][curPoint.y] + next.weight) continue;
                    dist[nextCur.x][nextCur.y] = dist[curPoint.x][curPoint.y] + next.weight;
                    pq.add(new Node(new Point(nextCur.x, nextCur.y), dist[nextCur.x][nextCur.y]));
                }
            }

            System.out.println("Problem " + t++ +": "+ dist[n-1][n-1]);
        }
    }
}
