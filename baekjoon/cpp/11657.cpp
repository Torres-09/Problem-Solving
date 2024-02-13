// 벨만 포드 알고리즘
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> dis;
vector<pair<int, pair<int, int>>> edge;
bool isCycle = false;

void solve()
{
	cin >> n >> m;
	int start, end, weight;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> weight;
		edge.push_back({ weight ,{start,end} });
	}

	dis.assign(501, INT_MAX);

	dis[1] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dis[edge[j].second.first] < INT_MAX && dis[edge[j].second.first] + edge[j].first < dis[edge[j].second.second])
				dis[edge[j].second.second] = dis[edge[j].second.first] + edge[j].first;
		}
	}


	for (int j = 0; j < m; j++)
	{
		if (dis[edge[j].second.first] < INT_MAX && dis[edge[j].second.first] + edge[j].first < dis[edge[j].second.second])
		{
			isCycle = true;
			break;
		}
	}

	if (isCycle)
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dis[i] == INT_MAX)
				cout << "-1\n";
			else
				cout << dis[i] << "\n";
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