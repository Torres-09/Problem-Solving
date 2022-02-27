#include<bits/stdc++.h>
using namespace std;
string a, b;
int dp[1001][1001];
int result = 0;

void solve()
{
	cin >> a >> b;

	for (int i = 0; i < a.size()+1; i++)
	{
		for (int j = 0; j < b.size()+1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			result = max(result, dp[i][j]);
		}
	}

	cout << result;
}

int main()
{
	solve();
}