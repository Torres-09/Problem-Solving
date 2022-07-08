#include<bits/stdc++.h>
using namespace std;
int n;
int num[101];
long long dp[101][21];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	dp[0][num[0]]++;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j + num[i] <= 20)
				dp[i][j] += dp[i - 1][j + num[i]];
			if (j - num[i] >= 0)
				dp[i][j] += dp[i - 1][j - num[i]];
		}
	}

	cout << dp[n - 2][num[n - 1]];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}