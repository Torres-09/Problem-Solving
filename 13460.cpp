#include<bits/stdc++.h>
using namespace std;
int n, m;
struct info {
	int rx, ry;
	int bx, by;
	int count;
};
char graph[11][11];
queue<info> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool Visit[11][11][11][11];

int bfs()
{
	int result = -1;

	while (!q.empty())
	{
		info cur = q.front();
		q.pop();

		if (cur.count > 10)
			break;

		if (graph[cur.rx][cur.ry] == 'O' && graph[cur.bx][cur.by] != 'O')
		{
			result = cur.count;
			return result;
		}

		for (int i = 0; i < 4; i++)
		{
			info next;
			int next_rx = cur.rx ;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;
			int next_count = cur.count + 1;

			while (1)
			{
				if (graph[next_rx][next_ry] != '#' && graph[next_rx][next_ry] != 'O')
				{
					next_rx += dx[i];
					next_ry += dy[i];
				}
				else 
				{
					if (graph[next_rx][next_ry] == '#')
					{
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
					break;
				}
			}

			while (1)
			{
				if (graph[next_bx][next_by] != '#' && graph[next_bx][next_by] != 'O')
				{
					next_bx += dx[i];
					next_by += dy[i];
				}
				else 
				{
					if (graph[next_bx][next_by] == '#') {
						next_bx -= dx[i];
						next_by -= dy[i];
					}
					break;
				}
			}

			if (next_rx == next_bx && next_ry == next_by)
			{
				if (graph[next_rx][next_ry] != 'O')
				{
					int red_dis = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
					int blue_dis = abs(next_bx - cur.bx) + abs(next_by - cur.by);

					if (red_dis > blue_dis)
					{
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
					else
					{
						next_bx -= dx[i];
						next_by -= dy[i];
					}
				}
				else
					continue;
			}

			if (Visit[next_rx][next_ry][next_bx][next_by] == false)
			{
				Visit[next_rx][next_ry][next_bx][next_by] = true;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.count = next_count;
				q.push(next);
			}
		}
	}

	return result;
}

void solve()
{
	cin >> n >> m;
	info start;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 'R')
			{
				start.rx = i;
				start.ry = j;
			}
			if (graph[i][j] == 'B')
			{
				start.bx = i;
				start.by = j;
			}
		}
	}

	start.count = 0;
	Visit[start.rx][start.ry][start.bx][start.by] = true;
	q.push(start);

	cout << bfs();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}