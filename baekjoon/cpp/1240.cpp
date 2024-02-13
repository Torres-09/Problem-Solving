#include<bits/stdc++.h>
using namespace std;
bool check[10001];
vector<pair<int, int>> graph[10001];

void dfs(int vertex, int des, int dis)
{
	if (check[vertex] == true)
		return;

	check[vertex] = true;
	if (vertex == des)
	{
		cout << dis << "\n";
		return;
	}

	for (int i = 0; i < graph[vertex].size(); i++)
	{
		dfs(graph[vertex][i].first, des, dis+graph[vertex][i].second);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	int start, end, weight;
	for (int i = 0; i < n-1; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
		graph[end].push_back({ start,weight });
	}

	int left, right;
	for (int i = 0; i < m; i++)
	{
		memset(check, false, sizeof(check));
		cin >> left >> right;
		dfs(left, right,0);
	}
}

int main()
{
	solve();
}