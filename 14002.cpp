#include<bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int a[1001];
int dp[1001];
vector<int> v;
stack<int> ans;

void solve()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	v.push_back(a[1]);

	for (int i = 1; i <= n; i++)
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

	int seq_size = cnt;

	for (int i = n; i >= 0; i--)
	{
		if (dp[i] == seq_size)
		{
			ans.push(a[i]);
			seq_size--;
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
	solve();
}