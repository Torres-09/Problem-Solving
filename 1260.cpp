// DFS¿Í BFS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> graph[1001];
queue<int> q;
bool visit[1001];
int n, m,v;

void DFS(int start)
{
	visit[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visit[graph[start][i]] == false)
		{
			DFS(graph[start][i]);
		}
	}
}

void BFS(int start)
{
	visit[start] = true;
	q.push(start);
	cout << start << " ";

	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (int i = 0; i < graph[start].size(); i++)
		{
			if (visit[graph[start][i]] == false)
			{
				q.push(graph[start][i]);
				cout << graph[start][i] << " ";
				visit[graph[start][i]] = true;
			}
		}
	}

	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	for (int i = 0; i <= n; i++)
	{
		visit[i] = false;
	}

	int start;
	int end;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 0; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	cout << "\n";

	for (int i = 0; i <= n; i++)
	{
		visit[i] = false;
	}

	BFS(v);
}