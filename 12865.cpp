#include<bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> item[101];	// weight, value
int dp[101][100001] = { 0 };	// item, weight

void solve()
{
	int weight, value;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> weight >> value;
		item[i] = make_pair(weight, value);
	}

	for (int i = 0; i <= k; i++)
	{
		if (i >= item[0].first)
			dp[0][i] = item[0].second;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= item[i].first)
				dp[i][j] = max(item[i].second + dp[i - 1][j - item[i].first], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n - 1][k];
}

int main()
{
	solve();
}