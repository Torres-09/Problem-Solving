#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int graph[101][101];
bool visit[101][101];
int n, m;
queue<pair<int,int>> q;

void BFS(int u, int v)
{
	pair<int, int> point;
	q.push({ u,v });
	while (!q.empty())
	{
		point = q.front();
		q.pop();

		if(point.first != 0)
			if (visit[point.first - 1][point.second] == false)
			{
				if (graph[point.first - 1][point.second] != 0)
				{
					q.push({ point.first - 1, point.second });
					visit[point.first - 1][point.second] = true;
					graph[point.first - 1][point.second] += graph[point.first][point.second];
				}
			}

		if(point.first!=n-1)
			if (visit[point.first + 1][point.second] == false)
			{
				if (graph[point.first + 1][point.second] != 0)
				{
					q.push({ point.first + 1,point.second });
					visit[point.first + 1][point.second] = true;
					graph[point.first + 1][point.second] += graph[point.first][point.second];
				}
			}

		if(point.second !=0)
			if (visit[point.first][point.second - 1] == false)
			{
				if (graph[point.first][point.second - 1] != 0)
				{
					q.push({ point.first,point.second - 1 });
					visit[point.first][point.second - 1] = true;
					graph[point.first ][point.second-1] += graph[point.first][point.second];
				}
			}

		if(point.second != m)
			if (visit[point.first][point.second + 1] == false)
			{
				if (graph[point.first][point.second + 1] != 0)
				{
					q.push({ point.first,point.second + 1 });
					visit[point.first][point.second + 1] = true;
					graph[point.first][point.second+1] += graph[point.first][point.second];
				}
			}


	}
}

int main()
{
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			graph[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = false;
		}
	}

	BFS(0, 0);
	cout << graph[n-1][m-1];
}