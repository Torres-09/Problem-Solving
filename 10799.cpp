#include<stack>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string str;
    getline(cin,str);
    int cur = 0;
    int result = 0;
    stack<char> s;
    for(char c : str){
        if(c=='(')
        {
            cur++;
            s.push(c);
        }
        else if(c==')'){
            cur--;
            // 레이저라면
            if(s.top()=='('){
                //전에 넣었던 게 금속과 무관
                s.push(c);
                result += cur;
            }
            // 레이저가 아니고 금속이 끝나는 부분
            else if(s.top()==')'){
                s.push(c);
                result += 1;
            }
        }
    }
    cout << result;
}