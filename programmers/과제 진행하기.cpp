#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<string> v1, vector<string> v2){
    return v1[1] < v2[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    // 과목이름, 시작시간, 소요시간
    sort(plans.begin(),plans.end(),cmp);
    
    // 현재시간
    int now = stoi(plans[0][1].substr(0,2)) * 60 + stoi(plans[0][1].substr(3,2));
    // 소요시간
    int rest = stoi(plans[0][2]);
    // 시작한 작업의 개수 ( 전체 개수와 같아지면 거기서 종료 )
    int index = 1;
    
    stack<pair<string,int>> name;
    
    while(index != plans.size()){
        int next = stoi(plans[index][1].substr(0,2)) * 60 + stoi(plans[index][1].substr(3,2));
        // 진행하던 작업을 끝내는 경우
        if(now + rest <= next)
            answer.push_back(plans[index-1][0]);
        // 다음 작업을 진행해야 되는 경우
        else
            name.push({plans[index-1][0], rest -(next-now)});
        
        int real_now = now + rest;
        now = next;
        rest = stoi(plans[index][2]);
        index++;
        
        // 작업을 마쳤는 데 다음 진행시간이 아직 안되어서 이전에 하던 과제를 해결하는 로직
        while(real_now < now){
            if(name.empty()) break;
            int temp_rest = name.top().second;
            cout << temp_rest << " " << real_now << " " << now << "\n";
            if(real_now + temp_rest <= now){
                answer.push_back(name.top().first);
                real_now += temp_rest;
                name.pop();
            }
            else{
                string temp_name = name.top().first;
                name.pop();
                name.push({temp_name, temp_rest - (now - real_now)});
                real_now = now;
            }
        }
        
        if(index == plans.size())
            answer.push_back(plans[index-1][0]);
    }
    
    while(!name.empty()){
        answer.push_back(name.top().first);
        name.pop();
    }
    
    return answer;
}
