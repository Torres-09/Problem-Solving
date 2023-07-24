#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;
long answer;
vector<long> v;
stack<long> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    v.assign(100002,0);
    for(int i =1;i<=n;i++){
        int num;
        cin >> num;
        v[i] = num;
    }

    s.push(0);

    // 마지막 공간까지 넓이계산이 필요하다 -> n+1까지 반복해야 된다.
    for(int i =1;i<=n+1;i++){
        // 새로 등장하는 높이가 더 낮은 경우 -> 해당 높이까지 포함해서 넓이계산이 불가 -> 이전 블럭들의 높이들을 계산한다.
        while(!s.empty() && v[s.top()] > v[i]){
            // 가장 최근 들어온 높이
            int index = s.top();
            s.pop();

            // 가장 최근 높이 * (가로길이)
            answer = max(answer, v[index] * (i-s.top()-1));
        }
        s.push(i);
    }

    cout << answer;
}