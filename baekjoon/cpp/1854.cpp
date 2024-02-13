#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, k;
priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
priority_queue<int,vector<int>, less<int>> Visited[1001];
vector<pair<int, int>> graph[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int start, end, weight;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end,weight });
		
	}
	 
	pq.push({ 0,1 });
	Visited[1].push(0);
	while(!pq.empty())
	{
		int cur = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int next_dis = dis + graph[cur][i].second;

			if (Visited[next].size() == k && next_dis < Visited[next].top())
				Visited[next].pop();

			if (Visited[next].size() < k)
			{
				Visited[next].push(next_dis);
				pq.push({ next_dis,next });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (Visited[i].size() < k)
			cout << "-1\n";
		else
			cout << Visited[i].top() << "\n";
	}
}