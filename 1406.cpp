#include <stack>
#include <iostream>
#include<cstring>
using namespace std;
stack<char> s1;
stack<char> s2;
char answer[600001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    int m;
    cin >> s;
    cin >> m;
    for (int i = 0; i < s.size(); i++)
    {
        s1.push(s[i]);
    }

    for (int i = 0; i < m; i++)
    {
        // 커서 한 칸 왼쪽으로 옮긴다.
        char cmd;
        cin >> cmd;
        if (cmd == 'L')
        {
            if (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // 커서 한 칸 오른쪽으로 이동
        else if (cmd == 'D'){
            if(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(cmd == 'B'){
            if(!s1.empty()){
                s1.pop();
            }
        }
        else if(cmd == 'P'){
            char a;
            cin >> a;
            s1.push(a);
        }
    }
    int answer_size = s1.size() + s2.size();
    int index = s1.size();
    int index2 = index;
    index--;
    while(!s1.empty()){
        answer[index] = s1.top();
        s1.pop();
        index--;
    }
    while(!s2.empty()){
        answer[index2] = s2.top();
        s2.pop();
        index2++;
    }

    for(int i =0;i<answer_size;i++){
        cout << answer[i];
    }
}