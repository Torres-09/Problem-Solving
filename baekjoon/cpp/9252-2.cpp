#include <iostream>
#include <algorithm>
#include <string>
int dp[1111][1111];
using namespace std;
string s1, s2, s3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s1 >> s2;
    int result = 0;
    if(s1.length() > s2.length()) swap(s1, s2);
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            // 같은 경우
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // 같지 않은 경우
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

            result = max(result, dp[i][j]);
        }
    }

    int x = s1.length();
    int y = s2.length();

    while (1)
    {
        // 0에 도달하면 이동 종료
        if (dp[x][y] == 0)
            break;

        // 위쪽이랑 비교 (같으면 위쪽으로 이동)
        if (dp[x][y] == dp[x - 1][y])
        {
            x--;
            continue;
        }

        // 위쪽이랑 같지 않으면 왼쪽이랑 비교 (같으면 왼쪽으로 이동)
        else if (dp[x][y] == dp[x][y - 1])
        {
            y--;
            continue;
        }
        else if(dp[x][y]-1 == dp[x-1][y-1]){
            x--;
            y--;
            s3+=s1[x];
        }
        // 위쪽과 왼쪽 모두 같지 않으면 위쪽으로 이동한다. 그리고 해당 문자를 LCS에 추가한다.
    }


    cout << result;
    if(result != 0){
        reverse(s3.begin(),s3.end());
        cout << "\n" << s3;
    }
}