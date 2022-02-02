// 벽 부수고 이동하기
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int graph[1001][1001];
int n, m;
bool visit[1001][1001];
int result[1001][1001];
bool change[1001][1001];
queue<pair<int,int>> q;
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0 , 0, -1, -1 };

void BFS()
{
	while (!q.empty())
	{
		pair<int, int> point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = point.first + dx[i];
			int next_y = point.second + dy[i];

			if (0 <= next_x && next_x <= n && 0 <= next_y && next_y <= m)
			{
				if (graph[next_x][next_y] == 0)
				{
					result[next_x][next_y] = result[point.first][point.second] + 1;
					visit[next_x][next_y] = true;
					q.push({ next_x,next_y });
				}
			}
		}
	}
}

int main()
{
	char c;
	cin >> n >> m;

	for (int i = 0; i < 1001; i++)
	{
		memset(result, 10, sizeof(int) * 1001);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			graph[i][j] = c - '0';

			if (graph[i][j] == 0)
				change[i][j] = true;
			else
				change[i][j] = false;
		}
	}

	q.push({ 0,0 });
	visit[0][0] = true;

	cout << result[n - 1][m - 1] << "\n";
}