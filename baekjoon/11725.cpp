#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> graph[100002];
int parent[100002];
int n;
bool visit[100002];
queue<int> q;

void bfs(int start)
{
	q.push(start);

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (visit[graph[vertex][i]] == false)
			{
				q.push(graph[vertex][i]);
				parent[graph[vertex][i]] = vertex;
				visit[graph[vertex][i]] = true;
			}

		}
	}
}

int main()
{
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}