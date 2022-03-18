#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[10001];
int maxdis = 0;
int maxvertex;
bool visit_check[10001];

void dfs(int start, int dist)
{
	if (visit_check[start] == true)
		return;

	visit_check[start] = true;

	if (dist > maxdis)
	{
		maxdis = dist;
		maxvertex = start;
	}

	for (int i = 0; i < graph[start].size(); i++)
	{
		dfs(graph[start][i].first, dist + graph[start][i].second);
	}
}

void solve()
{
	int n;
	cin >> n;

	int start, end, weight;
	for (int i = 0; i < n-1; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
		graph[end].push_back({ start,weight });
	}

	dfs(1, 0);
	memset(visit_check, false, sizeof(visit_check));
	dfs(maxvertex, 0);

	cout << maxdis;
}

int main()
{
	solve();
}