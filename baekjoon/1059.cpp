#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int l;

void solve()
{

	cin >> l;
	int a;

	for (int i = 0; i < l; i++)
	{
		cin >> a;
		s.push_back(a);
	}

	sort(s.begin(), s.end());

	int n;
	cin >> n;

	int ans = 0;

	if (n < s.front())
	{
		for (int i = 1; i < s.front(); i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (i >= n && j <= n)
					ans++;
			}
		}

		cout << ans;
		return;
	}
	
	int min_ele = 0;
	int max_ele = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > n)
		{
			min_ele = s[i-1] + 1;
			break;
		}
	}
	for (int j = s.size() - 1; j >=0; j--)
	{
		if (s[j] < n)
		{
			max_ele = s[j + 1] - 1;
			break;
		}
	}

	

	for (int i = min_ele; i <= max_ele; i++)
	{
		for (int j = min_ele; j < i; j++)
		{
			if (i >= n && j <= n)
				ans++;
		}
	}

	cout << ans;
}

int main()
{
	solve();
}