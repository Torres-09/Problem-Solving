// 줄세우기
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[32001];
queue<int> q;
int Count[32001];

void solve()
{
	cin >> n >> m;

	int start, end;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		v[start].push_back(end);
		Count[end]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (Count[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++)
		{
			Count[v[cur][i]]--;

			if (Count[v[cur][i]] == 0)q.push(v[cur][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}