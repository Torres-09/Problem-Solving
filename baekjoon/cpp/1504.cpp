#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[20001];		// 그래프
vector<int> d;


int dijkstra(int start, int end)
{
	d.assign(20001, INT_MAX);	// distance ( 시작점으로부터 각 정점까지의 거리 )

	d[start] = 0;		// 본인까지의 거리는 0

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fringe;
	fringe.push({ 0, start });

	while (!fringe.empty())
	{
		int cur = fringe.top().second;
		int dis = fringe.top().first;

		fringe.pop();

		if (d[cur] < dis)
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int next_dis = dis + graph[cur][i].second;

			if (next_dis < d[next])
			{
				d[next] = next_dis;
				fringe.push({ next_dis,next });
			}
		}
	}

	if (d[end] == INT_MAX)
	{
		cout << "-1\n";
		exit(0);
	}

	return d[end];
}

void solve()
{
	int v, e;
	cin >> v >> e;

	int start, end, weight;		// start - > end ( weight ) 
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
		graph[end].push_back({ start,weight });
	}

	int root;		// 시작점
	cin >> root;

	int across;		// 도착점
	cin >> across;

	int temp = dijkstra(1, root);
	temp += dijkstra(root, across);
	temp += dijkstra(across, v);

	int temp2 = dijkstra(1, across);
	temp2 += dijkstra(across, root);
	temp2 += dijkstra(root, v);

	cout << min(temp, temp2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}