#include<bits/stdc++.h>
using namespace std;
vector<int> v(1001);
vector<int > dp(1001);
int n;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		dp[i] = v[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (v[i] < v[j] && dp[j] < dp[i] + v[j])
				dp[j] = dp[i] + v[j];
		}
	}

	sort(dp.begin(), dp.end(), greater<int>());
	
	cout << dp[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
