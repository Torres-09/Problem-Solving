#include<bits/stdc++.h>
using namespace std;


void solve()
{
	string s;
	cin >> s;
	string ss;
	set<string> a;

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length(); j++)
		{
			if (i + j > s.length())
				break;

			ss = s.substr(i, j);
			a.insert(ss);
		}
	}

	cout << a.size();
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}