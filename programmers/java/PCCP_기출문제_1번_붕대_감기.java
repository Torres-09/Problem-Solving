package com.programmers.java;

import java.util.*;

class PCCP_기출문제_1번_붕대_감기 {
    static int castingTime, healSec, healAdd;
    static int wave;
    static HashMap<Integer, Integer> monsters = new HashMap<>();
    static int cnt;
    static int hp;
    public int solution(int[] bandage, int health, int[][] attacks) {
        castingTime = bandage[0];
        healSec = bandage[1];
        healAdd = bandage[2];
        hp = health;
        
        for(int i =0;i<attacks.length;i++){
            monsters.put(attacks[i][0], attacks[i][1]);
        }
        
        for(int i =0;i<=attacks[attacks.length-1][0];i++){
            if(monsters.containsKey(i)){
                cnt = 0;
                hp -= monsters.get(i);
                if(hp <= 0) return -1;
                continue;
            }
            
            cnt++;
            if(cnt == castingTime){
                cnt = 0;
                hp += healAdd;
            } 
            hp += healSec;
        
            
            if(hp >= health) hp = health;
        }
        return hp;
    }
}