#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = 0;
    long sum2 = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    for(auto i : queue1){
        sum1 += i;
        q1.push(i);
    }
    for(auto i: queue2){
        sum2 += i;
        q2.push(i);
    }
    
    
    long total_sum = sum1 + sum2;
    
    while(sum1!=total_sum/2 || sum2!= total_sum/2){
        answer++;
        if(sum1>sum2){
            int num = q1.front();
            q2.push(num);
            sum1 -= num;
            sum2 += num;
            q1.pop();
        }else{
            int num = q2.front();
            q1.push(num);
            sum2 -= num;
            sum1 += num;
            q2.pop();
        }
        
        if(answer >= 300000) return -1;
    }
    
    return answer;
}
