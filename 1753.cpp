#include<bits/stdc++.h>
using namespace std;

void solve()
{
	vector<pair<int, int>> graph[20001];		// 그래프
	vector<bool> visit;
	int v, e;
	cin >> v >> e;

	visit.assign(v, false);

	int root;		// 시작점
	cin >> root;

	int start, end, weight;		// start - > end ( weight ) 
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
	}

	vector<int> d;
	d.assign(20001, INT_MAX);	// distance ( 시작점으로부터 각 정점까지의 거리 )

	d[root] = 0;		// 본인까지의 거리는 0

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fringe;
	fringe.push({ 0, root });

	while (!fringe.empty())
	{
		int cur = fringe.top().second;
		int dis = fringe.top().first;

		fringe.pop();
		visit[cur] = true;

		if (d[cur] < dis)
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int next_dis = dis + graph[cur][i].second;

			if (visit[next])continue;

			if (next_dis < d[next])
			{
				d[next] = next_dis;
				fringe.push({ next_dis,next });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INT_MAX)
		{
			cout << "INF\n";
			continue;
		}

		cout << d[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}

// 우선순위 큐에 pair를 저장해서 거리를 비교하려면, first 부분에 반드시 거리가 들어가야 한다. 그래야 거리가
// 낮은 순서부터 꺼내서 비교한다. 이거 때문에 굉장히 오래 고생 ..ㅜㅜ