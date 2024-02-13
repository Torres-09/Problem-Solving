// 벽 부수고 이동하기
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int graph[1001][1001];
int visit[1001][1001][2];
queue<pair<pair<int,int>,int>> q;
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0 , 0, -1, 1 };

int BFS()
{
	q.push({ { 0,0 }, 1 });
	visit[0][0][1] = 1;
	while (!q.empty())
	{
		pair<int, int> point = q.front().first;
		int block = q.front().second;
		q.pop();

		if (point.first == n - 1 && point.second == m - 1)
		{
			return visit[point.first][point.second][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = point.first + dx[i];
			int next_y = point.second + dy[i];

			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m)
			{
				if (graph[next_x][next_y] == 1 && block == 1)
				{
					q.push({ {next_x,next_y }, block-1 });
					visit[next_x][next_y][block - 1] = visit[point.first][point.second][block] + 1;
				}

				if (graph[next_x][next_y] == 0&&visit[next_x][next_y][block]==0)
				{
					q.push({ {next_x,next_y}, block });
					visit[next_x][next_y][block] = visit[point.first][point.second][block] + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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

	cout << BFS() << "\n";
}