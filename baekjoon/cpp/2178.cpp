// ¹Ì·Î Å½»ö
// BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int graph[101][101];
bool visit[101][101];
int n, m;
queue<pair<int, int>> q;
int dx[4] = { -1 , 1, 0, 0 };
int dy[4] = { 0, 0 , -1, 1 };

void BFS(int u, int v)
{
	pair<int, int> point;
	q.push({ u,v });
	visit[u][v] = true;
	while (!q.empty())
	{
		point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = point.first + dx[i];
			int next_y = point.second + dy[i];

			if (0 <= next_x && next_x <= n && 0 <= next_y && next_y <= m)
			{
				if (visit[next_x][next_y] == false && graph[next_x][next_y] != 0)
				{
					q.push({ next_x,next_y });
					visit[next_x][next_y] = true;
					graph[next_x][next_y] += graph[point.first][point.second];
				}
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
	cout << graph[n - 1][m - 1];
}