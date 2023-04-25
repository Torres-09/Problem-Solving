#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> um;
    map<int, string> um2;
    int index = 1;
    for(auto i:players){
        um.insert({i,index});
        um2.insert({index++, i});
    }
    
    for(string i : callings){
        // 앞에 있던 사람
        string temp = um2[um[i] - 1];
        um2[um[i]] = temp;
        um2[um[i] - 1] = i;
        
        um[temp] += 1;
        um[i] -= 1;
        
    }
    
    for(auto i : um2){
        answer.push_back(i.second);
    }
    
    return answer;
}
