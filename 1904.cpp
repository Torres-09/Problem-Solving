#include<iostream>
using namespace std;
int dp[1000002];
int n;

void solve()
{
	for (int i = 3; i < 1000001; i++)
	{
		dp[i] = (dp[i - 1] % 15746 + dp[i - 2] % 15746)%15746;
	}

	cin >> n;
	cout << dp[n];
}

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	solve();
}