#include<bits/stdc++.h>

using namespace std;

int dp[10001];

int solution(int n) {
    int answer = 0;
    
    int i = 0;
    int j = 1;
    int k = 1;
    while(n - i > 0){
        if((n-i)%k == 0) answer++;
        
        k++;
        i += j;
        j++;
    }

    return answer;
}
