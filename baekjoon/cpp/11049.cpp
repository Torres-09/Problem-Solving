#include<limits>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int n, r, c;
vector<pair<int, int>> v;
long long dp[501][501];

void solve()
{
	v.push_back({ 0,0 });
	cin >> n;
	int n1, n2;
	for (int i = 0; i < n; i++)
	{
		cin >> n1 >> n2;
		v.push_back({ n1,n2 });
	}

	// min 사용하기 위해서 초기값 int 최대로
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}

	// 본인의 행렬곱은 0이다.
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
	}

	// 사선 DP 행렬곱
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; i + j - 1 <= n; j++)
		{
			for (int k = j; k <= i + j - 1; k++)
			{
				dp[j][j + i - 1] = min(dp[j][k] + dp[k + 1][i + j - 1] + v[j].first*v[k].second*v[i + j - 1].second, dp[j][j + i - 1]);
			}
		}
	}
	
	cout << dp[1][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}