// 토마토 - z축 추가
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int m, n, h;
int graph[101][101][101];
queue<tuple<int, int, int>> q;
int max_value = 1;
tuple<int, int, int> point;

// 
int dx[6] = { -1 , 1, 0, 0,0,0 };
int dy[6] = { 0, 0 , -1, 1,0,0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void BFS()
{
	while (!q.empty())
	{
		point = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int next_z = get<0>(point) + dz[i];
			int next_x = get<1>(point) + dx[i];
			int next_y = get<2>(point) + dy[i];

			if (0 <= next_x && next_x <= n && 0 <= next_y && next_y <= m && 0 <= next_z && next_z <= h)
			{
				if (graph[next_z][next_x][next_y] == 0)
				{
					q.push(make_tuple(next_z, next_x, next_y));
					graph[next_z][next_x][next_y] += graph[get<0>(point)][get<1>(point)][get<2>(point)] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> m >> n >> h;
	int to;
	int zero_count = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				graph[i][j][k] = -2;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> to;
				graph[i][j][k] = to;

				if (to == 1)
				{
					q.push(make_tuple(i, j, k));
				}

				if (to == 0)
					zero_count++;
			}
		}
	}

	if (zero_count == 0)
	{
		cout << "0\n";
		return 0;
	}

	BFS();


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (graph[i][j][k] == 0)
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				max_value = max(max_value, graph[i][j][k]);
			}
		}
	}

	cout << max_value - 1 << "\n";
}