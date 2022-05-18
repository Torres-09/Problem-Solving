#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<long, int> s;
	int n, m;

	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s.insert({ num,i });
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (s.find(num) == s.end())
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}
}