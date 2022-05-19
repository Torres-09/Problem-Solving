#include<bits/stdc++.h>
using namespace std;

void solve()
{
	unordered_map<string, int> um1;
	vector<string> v;

	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		um1.insert({ s,i });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s;

		if (!(um1.find(s) == um1.end()))
			v.push_back(s);
	}

	cout << v.size() << "\n";
	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}