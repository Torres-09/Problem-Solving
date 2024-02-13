#include<bits/stdc++.h>
using namespace std;


void solve()
{
	unordered_map<string, int> um;
	unordered_map<int, string> um_2;
	int n, m;
	string name;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> name;
		um.insert({ name,i });
		um_2.insert({ i , name });
	}

	string cmd;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;

		if (isdigit(cmd[0]))
			cout << um_2[stoi(cmd)] << "\n";
		else
			cout << um[cmd] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}