#include<iostream>
#include<algorithm>
using namespace std;

int podo[10001];
int dp[10001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> podo[i];
	}

	dp[0] = podo[0];
	dp[1] = dp[0] + podo[1];
	dp[2] = max(max(podo[2] + podo[1], podo[2] + dp[0]), dp[1]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(max(dp[i - 1], podo[i] + podo[i - 1] + dp[i - 3]), podo[i] + dp[i - 2]);
	}

	cout << dp[n - 1] << "\n";
}