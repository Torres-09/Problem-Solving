#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    int temp = sequence[0];
    int left_answer = 0;
    int right_answer = sequence.size();
    
    while(right != sequence.size()){
        if(temp == k){
            if(right - left < right_answer - left_answer){
                left_answer = left;
                right_answer = right;
            }
            temp -= sequence[left];
            left++;
        }else if(temp > k){
            temp -= sequence[left];
            left++;
        }else if(temp < k){
            right++;
            temp += sequence[right];
        }
    }
    
    answer = {left_answer,right_answer};
    
    return answer;
}
