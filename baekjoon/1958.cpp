#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s1, s2, s3;
int dp[105][105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s1 >> s2 >> s3;
    int result = 0;

    for(int i =0;i<=s1.size();i++){
        for(int j =0;j<=s2.size();j++){
            for(int k=0;k<=s3.size();k++){
                if(i == 0 || j==0||k==0) dp[i][j][k] = 0;
                // 기존 두 개의 문자열에 대해서는 끝이 같은 지 비교
                // 3개의 문자열에서는 모두 같아야지만 + 1
                else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;

                // 같지 않다면 3개의 위치에 대해서 비교하고, 큰 값으로 select
                else{
                    // 기존 것과 두 가지 위치에 대하여 비교
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k], dp[i][j-1][k]));
                    // 기존 것과 나머지 한 가지 위치에 대하여 비교
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                }

                result = max(result, dp[i][j][k]);
            }
        }
    }

    cout << result;
}