#include<bits/stdc++.h>
using namespace std;
int n, m;
int graph[51][51];
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0,0,-1, 1 };
int dp[51][51];

int DFS(int x, int y)
{
	if (x >= n || x < 0 || y < 0 || y >= m || graph[x][y] == 0)
		return 0;


	int result = -1;

	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i] * graph[x][y];
			int next_y = y + dy[i] * graph[x][y];

			int r = DFS(next_x, next_y) + 1;
			if(result<r)result = r;
		}

		dp[x][y] = result;
		return dp[x][y];
	}
	else if (dp[x][y] == 0)
	{
		cout << -1;
		exit(0);
	}
	else
		return dp[x][y];
}

void solve()
{
	cin >> n >> m;
	char c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			graph[i][j] = c - '0';

			if (graph[i][j] > 9 || graph[i][j] < 1)
				graph[i][j] = 0;

			dp[i][j] = -1;
		}
	}

	DFS(0, 0);
	cout << dp[0][0];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}