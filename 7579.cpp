#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int now_memory[101];
int cost[101];
int dp[101][10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> now_memory[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < cost[i]; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}

		for (int j = cost[i]; j < 10001; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + now_memory[i]);
		}
	}

	int answer;
	for (int i = 0; i < 10001; i++)
	{
		if (dp[n][i] >= m)
		{
			answer = i;
			break;
		}
	}
	cout << answer;
}