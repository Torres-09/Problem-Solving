#include<bits/stdc++.h>
using namespace std;
int t;

void solve()
{
	map<string, int> m;
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0\n";
		return;
	}


	string a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		if (m.find(b) == m.end())
		{
			m.insert({ b,1 });
		}
		else
		{
			auto it = m.find(b);
			it->second++;
		}
	}

	int result = 1;
	for (auto it = m.begin(); it!=m.end(); it++)
	{
		result *= it->second + 1;
	}
	cout << result - 1 << "\n";
	
}

int main()
{
	cin >> t;
	while (t--)
	{
		solve();
	}
}