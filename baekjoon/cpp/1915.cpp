// 가장 큰 정사각형
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int num[1001][1001];
int dp[1001][1001];
int n, m;

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &num[i][j]);
		}
	}

	// 첫 번째 행의 dp 값은 1
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = num[1][i];
	}

	// 첫 번째 열의 dp 값은 1
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = num[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 || j == 1)continue;

			if (num[i][j] == 0)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = min(min(dp[i-1][j-1],dp[i - 1][j]), dp[i][j - 1]) + 1;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			answer = max(answer, dp[i][j]);
		}
	}

	printf("%d", answer*answer);
}

int main()
{
	solve();
}