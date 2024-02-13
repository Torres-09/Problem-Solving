#include <iostream>
#include <algorithm>
#include <string>
int dp[1001][1001];
using namespace std;
string s1, s2, s3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s1 >> s2;
    int result = 0;
    for (int i = 0; i < s1.size() + 1; i++)
    {
        for (int j = 0; j < s2.size() + 1; j++)
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

    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "1"
         << "\n";

    int x = s1.size();
    int y = s2.size();
    cout << x << " " << y;
    while (1)
    {
        // 0에 도달하면 이동 종료
        if (dp[x][y] == 0)
            break;

        // 위쪽이랑 비교 (같으면 위쪽으로 이동)
        if (dp[x][y] == dp[x - 1][y])
        {
            x = x--;
            continue;
        }

        // 위쪽이랑 같지 않으면 왼쪽이랑 비교 (같으면 왼쪽으로 이동)
        if (dp[x][y] == dp[x][y - 1])
        {
            y = y--;
            continue;
        }

        // 위쪽과 왼쪽 모두 같지 않으면 위쪽으로 이동한다. 그리고 해당 문자를 LCS에 추가한다.
        x--;
        s3 = s3 + s1[x];
    }

    cout << s3;
}