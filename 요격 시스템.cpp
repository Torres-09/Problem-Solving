#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());
    int temp = targets[0][1];
    for (auto a : targets) {
        if (temp <= a[0]) {
            answer++;
            temp = a[1];
        }
        if (temp >= a[1])    temp = a[1];
    }
    return answer;
}
