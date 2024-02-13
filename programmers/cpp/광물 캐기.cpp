#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int total = 0;
    int s[3][3];
    s[0][0] = 1;
    s[0][1] = 1;
    s[0][2] = 1;
    s[1][0] = 5;
    s[1][1] = 1;
    s[1][2] = 1;
    s[2][0] = 25;
    s[2][1] = 5;
    s[2][2] = 1;
    
    for(auto i : picks){
        total += 5 * i;
    }
    
    pair<int,int> dp[11];
    for(int i=0;i<11;i++){
        dp[i].second = -1;
    }

    for(int i=0;i<minerals.size();i=i+5){
        // 캘 수 있는 양보다 뒤에 있는 광물의 위치라면 계산할 필요가 없음
        if(i >= total) break;
        
        for(int j=0;j<5;j++){
            // 곡괭이가 남아도는 경우에는 멈춘다.
            if(i+j >= minerals.size()) break;
            
            
            if(minerals[i + j] == "diamond"){
                dp[i/5 + i%5].first += 25;
                dp[i/5 + i%5].second = i;
            }
            else if(minerals[i + j] == "iron"){
                dp[i/5 + i%5].first += 5;
                dp[i/5 + i%5].second = i;
            }
            else{
                dp[i/5 + i%5].first += 1;
                dp[i/5 + i%5].second = i;
            }
        }
    }
    
    sort(dp,dp+11,greater<pair<int,int>>());
    
    // 첫 번째부터 큰 거 -> 다이아 철 돌 순으로 채굴하면 된다.
    for(int i =0;i<11;i++){
        if(dp[i].second == -1) break;
        
        int gock = 0;
        
        // 곡괭이 정하기
        if(picks[0] != 0){
            gock = 0;
            picks[0]--;
        }
        else if(picks[1] != 0){
            gock = 1;
            picks[1]--;
        }else if(picks[2] != 0){
            gock = 2;
            picks[2]--;
        }
        
        for(int j =0;j<5;j++){
            if(dp[i].second + j == minerals.size())
            {
                break;
            } 
            
            if(minerals[dp[i].second + j] == "diamond"){
                answer += s[gock][0];
            }else if(minerals[dp[i].second + j] == "iron"){
                answer += s[gock][1];
            }
            else{
                answer += s[gock][2];
            } 
        }
    }
    
    return answer;
}
