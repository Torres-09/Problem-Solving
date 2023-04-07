#include<bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<string> strs;
    string str;
    while(getline(ss,str,' ')){
        strs.push_back(str);
    }
    
    for(auto &i : strs){
        transform(i.begin(),i.end(),i.begin(), ::tolower);
        if(isalpha(i[0]))
            i[0] = toupper(i[0]);
    }
    
    for(int i =0;i<strs.size()-1;i++){
        answer += strs[i] + " ";
    }
    answer += strs.back();
    return answer;
}
