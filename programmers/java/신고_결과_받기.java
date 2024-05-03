package com.programmers.java;

import java.util.*;

class 신고_결과_받기 {
    static boolean[][] visit;
    static int[] reports;
    static HashMap<String, Integer> index = new HashMap<>();
    static int[] answer;
    public int[] solution(String[] id_list, String[] report, int k) {
        reports = new int[id_list.length];
        visit = new boolean[id_list.length][id_list.length];
        answer = new int[id_list.length];
        
        for(int i =0;i<id_list.length;i++){
            index.put(id_list[i], i);
        }
        
        for(String s: report){
            String[] splits = s.split(" ");
            if(visit[index.get(splits[0])][index.get(splits[1])]) continue;
            visit[index.get(splits[0])][index.get(splits[1])] = true;
            reports[index.get(splits[1])]++;
        }
        
        for(int i =0;i<id_list.length;i++){
            if(reports[i] >= k){
                for(int j =0;j<id_list.length;j++){
                    if(i == j) continue;
                    
                    if(visit[j][i]) answer[j]++;
                }
            } 
        }
        
        
        return answer;
    }
}