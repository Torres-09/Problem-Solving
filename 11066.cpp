#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // 각 페이지의 비용
        vector<int> page(n + 2, 0);
        // 1 ~ x 페이지까지 비용의 합
        vector<int> sum(n + 2, 0);

        // x ~ y 까지의 비용의 합 중 최소
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
        {
            cin >> page[i];
            sum[i] = sum[i - 1] + page[i];
        }

        // 범위의 크기 (시작부분 ~ 최대 n만큼)
        for (int i = 1; i <= n; i++)
        {
            // 시작부분 ( 1위치부터 n-범위만큼까지 )
            for (int j = 1; j <= n - i; j++)
            {
                dp[j][j+i] = 1000000000;
                // 중간부분 ( 시작위치부터 시작+범위 위치까지)
                for (int k = j; k < i + j; k++)
                    dp[j][i + j] = min(dp[j][i + j], sum[j + i] - sum[j - 1] + dp[j][k] + dp[k + 1][j + i]);
            }
        }

        cout << dp[1][n] << "\n";
    }
}