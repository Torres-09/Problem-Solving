#include<bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    stringstream ss(s);
    string num;
    while(getline(ss,num,' ')){
        nums.push_back(stoi(num));
    }
    
    answer += to_string(*min_element(nums.begin(),nums.end())) + " " + to_string(*max_element(nums.begin(),nums.end()));
    return answer;
}
