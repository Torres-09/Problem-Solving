#include<bits/stdc++.h>
using namespace std;

void solve()
{
	vector<pair<int, int>> graph[20001];		// �׷���
	vector<bool> visit;
	int v, e;
	cin >> v >> e;

	visit.assign(v, false);

	int root;		// ������
	cin >> root;

	int start, end, weight;		// start - > end ( weight ) 
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
	}

	vector<int> d;
	d.assign(20001, INT_MAX);	// distance ( ���������κ��� �� ���������� �Ÿ� )

	d[root] = 0;		// ���α����� �Ÿ��� 0

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

// �켱���� ť�� pair�� �����ؼ� �Ÿ��� ���Ϸ���, first �κп� �ݵ�� �Ÿ��� ���� �Ѵ�. �׷��� �Ÿ���
// ���� �������� ������ ���Ѵ�. �̰� ������ ������ ���� ��� ..�̤�