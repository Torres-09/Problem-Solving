#include<iostream>
#include<algorithm>
#include<string>
int dp[1001][1001];
using namespace std;
string s1,s2;
string s3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int result = 0;
    for(int i =0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){

            // 0번 째 index = " "
            if(i==0||j==0) dp[i][j] = 0;

            // 같은 경우
            else if(s1[i]==s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            // 같지 않은 경우
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }

            result = max(result,dp[i][j]);
        }
    }

    cout << dp[s1.size()-1][s2.size()-1];

    for(int i=1;i<s2.size();i++){
        if(dp[s1.size()-1][i]!=dp[s1.size()-1][i-1]) s3 += s1[i];
    }


    if(result!=0) cout << "\n" << s3;
}