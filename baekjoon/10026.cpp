#include<bits/stdc++.h>
using namespace std;
char graph[101][101];
int n;
bool Visit[101][101];
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int Count = 0;

void BFS(int n1,int n2)
{
	if (Visit[n1][n2] == true)
		return;

	q.push({ n1,n2 });
	Visit[n1][n2] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (Visit[next_x][next_y] == false && next_x>=0 && next_x<n && next_y>=0 && next_y<n)
			{
				
				if (graph[x][y] == graph[next_x][next_y])
				{
					Visit[next_x][next_y] = true;
					q.push({ next_x,next_y });
				}
			}
		}

		q.pop();
	}

	Count++;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int a;
	int b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Visit[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			BFS(i, j);
		}
	}

	a = Count;
	Count = 0;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 'R')
				graph[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Visit[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			BFS(i, j);
		}
	}

	b = Count;

	cout << a << " " << b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}