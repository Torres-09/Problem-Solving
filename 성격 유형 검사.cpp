#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char,int> um;
    um.insert({'R',0});
    um.insert({'T',0});
    um.insert({'C',0});
    um.insert({'F',0});
    um.insert({'J',0});
    um.insert({'M',0});
    um.insert({'A',0});
    um.insert({'N',0});
    for(int i =0;i<survey.size();i++){
        if(choices[i] == 1){
            um[survey[i][0]] += 3;
        }else if(choices[i] == 2){
            um[survey[i][0]] += 2;
        }else if(choices[i] == 3){
            um[survey[i][0]] += 1;
        }else if(choices[i] == 5){
            um[survey[i][1]] += 1;
        }else if(choices[i] == 6){
            um[survey[i][1]] += 2;
        }else if(choices[i] == 7){
            um[survey[i][1]] += 3;
        }
    }
    
    if(um['R'] >= um['T']) answer+='R';
    else answer+='T';
    if(um['C'] >= um['F']) answer+='C';
    else answer+='F';
    if(um['J'] >= um['M']) answer+='J';
    else answer+='M';
    if(um['A'] >= um['N']) answer+='A';
    else answer+='N';
    return answer;
}
