#include<bits/stdc++.h>
using namespace std;
int n, m;

void solve()
{
	cin >> n >> m;
	
	string s;
	unordered_map<string, int> um;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		um.insert({ s,i });
	}

	int check = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (!(um.find(s) == um.end()))
		{
			check++;
		}
	}

	cout << check;
}

int main()
{
	solve();
}