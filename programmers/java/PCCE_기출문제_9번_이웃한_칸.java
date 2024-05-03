package com.programmers.java;

class PCCE_기출문제_9번_이웃한_칸 {
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int answer;
    public int solution(String[][] board, int h, int w) {
        if(h-1 >= 0) if(board[h-1][w].equals(board[h][w])) answer++;
        if(h+1 < board.length) if(board[h+1][w].equals(board[h][w])) answer++;
        if(w-1 >= 0) if(board[h][w-1].equals(board[h][w])) answer++;
        if(w+1 < board[0].length) if(board[h][w+1].equals(board[h][w])) answer++;
        return answer;
    }
}