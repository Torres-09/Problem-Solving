#include<bits/stdc++.h>
using namespace std;


void solve()
{
	bool mode = false;
	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans++;
		if (mode == false)
		{
			if (s[i] <= 'z'&&s[i] >= 'a')
				continue;
			else
			{
				ans++;
				if (i + 1 < s.size())
				{
					if (s[i + 1] <= 'Z'&&s[i + 1] >= 'A')
					{
						mode = true;
					}
				}
			}
		}
		else
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')
				continue;
			else
			{
				ans++;
				if (i + 1 < s.size())
				{
					if (s[i + 1] <= 'z'&&s[i + 1] >= 'a')
					{
						mode = false;
					}
				}
			}
		}
	}

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}