#include<iostream>
#include<algorithm>
#include<string>
int dp[1001][1001];
using namespace std;
string s1,s2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s1 >> s2;
    int result = 0;
    for(int i =0;i<s1.size() +1;i++){
        for(int j=0;j<s2.size()+1;j++){
            if(i==0||j==0) dp[i][j] = 0;
            // 같은 경우
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            // 같지 않은 경우
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }

            result = max(result,dp[i][j]);
        }
    }

    cout << result;
}