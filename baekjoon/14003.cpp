#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int dp[1000005];
vector<int> v;
stack<int> ans;
int n;
int cnt;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	v.push_back(a[1]);

	for (int i = 2; i <= n; i++)
	{
		if (v[cnt] < a[i])
		{
			v.push_back(a[i]);
			cnt++;
			dp[i] = cnt;
		}
		else
		{
			int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[pos] = a[i];
			dp[i] = pos;
		}
	}

	for (int i = n; i >= 0; i--)
	{
		if (dp[i] == cnt)
		{
			ans.push(a[i]);
			cnt--;
		}
	}

	cout << ans.size() << "\n";
	while (!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}