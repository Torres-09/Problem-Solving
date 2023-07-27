#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

string s1;
string s2;
string s3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s1 >> s2 >> s3;

    int answer = 0;
    // 시작위치
    for(int i =0;i<s1.size();i++){
        // 사이즈
        for(int j =1;i+j <=s1.size();j++){
            auto a = s2.find(s1.substr(i,j));
            auto b = s3.find(s1.substr(i,j));

            if(a == string::npos | b == string::npos) continue;

            answer = max(answer, j);
        }
    }

    cout << answer;
}