#include<bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    queue<int> q;
    for(int i : section){
        q.push(i);
    }
    
    while(!q.empty()){
        answer++;
        int start = q.front();
        q.pop();
        while(!q.empty()&&q.front() <= start + m - 1){
            q.pop();
        }
    }
    
    return answer;
}
