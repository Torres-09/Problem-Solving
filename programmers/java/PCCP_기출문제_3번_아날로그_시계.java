package com.programmers.java;

class PCCP_기출문제_3번_아날로그_시계 {
    static int hour, min, sec;
    // 3600 * 12 = 43200
    
    static int start, end;
    static int answer;
    
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        start = h1 * 3600 + m1 * 60 + s1;
        end = h2 * 3600 + m2 * 60 + s2;
        
        hour = (h1%12) * 3600 + m1 * 60 + s1;
        min = m1 * 720 + s1 * 12;
        sec = s1 * 720;
        
        if(hour==min || hour == sec || sec == min) answer++;
        
        for(int i =start;i<end;i++){
            if(sec + 720 == hour + 1 && sec + 720 == min + 12){
                answer++;
            }else{
                if(sec < hour && sec + 720 >= hour +1) answer++;
                if(sec < min && sec + 720 >= min + 12) answer++;
            }
            
            hour += 1;
            min += 12;
            sec += 720;
            if(hour == 43200) hour = 0;
            if(min == 43200) min = 0;
            if(sec == 43200) sec = 0;
        }
        
        return answer;
    }
}