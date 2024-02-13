// 1로 만들기
#include<iostream>
using namespace std;
int n;
int dp[1000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 1000002; i++)
	{
		dp[i] = 0;
	}
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 2; i < 1000002; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0 && dp[i/3] +1 < dp[i])
		{
			dp[i] = dp[i / 3] + 1;
		}

		if (i % 2 == 0 && dp[i/2] + 1 < dp[i])
		{
			if (dp[i - 1] < dp[i / 2])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = dp[i / 2] + 1;
		}
	}
	
	cin >> n;
	cout << dp[n] << "\n";
	
}

