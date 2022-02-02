// 나이트의 이동
#include<iostream>
#include<queue>
using namespace std;
int t, l;
int a, b;
int c, d;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
bool visit[301][301];
int graph[301][301];
queue<pair<int,int>> q;


void BFS()
{
	while (!q.empty())
	{
		pair<int, int> point;
		point = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int next_x = point.first + dx[i];
			int next_y = point.second + dy[i];

			if (0 <= next_x && next_x < l && 0 <= next_y && next_y < l)
			{
				if (visit[next_x][next_y] == false)
				{
					q.push({ next_x,next_y });
					visit[next_x][next_y] = true;
					graph[next_x][next_y] = graph[point.first][point.second] + 1;
				}
			}

			if (next_x == c && next_y == d)
			{
				cout << graph[next_x][next_y] << "\n";

				while (!q.empty())
					q.pop();

				return;
			}
		}

		
	}
	cout << 0 << "\n";
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> l;

		cin >> a >> b;
		cin >> c >> d;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				graph[i][j] = 0;
			}
		}

		visit[a][b] = true;
		q.push({ a,b });

		BFS();
	}
}