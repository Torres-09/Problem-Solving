// ≈‰∏∂≈‰
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int m, n;
int graph[1001][1001];
queue<pair<int, int>> q;
int max_value = 1;
pair<int, int> point;
int dx[4] = { -1 , 1, 0, 0 };
int dy[4] = { 0, 0 , -1, 1 };

void BFS()
{
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
				if (graph[next_x][next_y] == 0)
				{
					q.push({ next_x,next_y });
					graph[next_x][next_y] += graph[point.first][point.second] + 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 1001; i++)
	{
		memset(graph[i], -2, sizeof(int) * 1001);
	}
	cin >> m >> n;
	int k;
	int zero_count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> k;
			graph[i][j] = k;

			if (k == 1)
				q.push({ i,j });

			if (k == 0)
				zero_count++;
		}
	}

	if (zero_count == 0)
	{
		cout << "0\n";
		return 0;
	}

	BFS();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			max_value = max(max_value, graph[i][j]);
		}
	}
	cout << max_value - 1 << "\n";
}