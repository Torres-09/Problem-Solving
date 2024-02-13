#include<bits/stdc++.h>
using namespace std;
char graph[51][51];
bool visi[51][51];
int n, m;
int ans = 0;

void visiting(int row, int col)
{
	if (visi[row][col] == true)
	{
		return;
	}

	if (row>=n||col>=m)
	{
		ans++;
		return;
	}

	visi[row][col] = true;

	if (graph[row][col]=='-')
	{
		if (graph[row][col + 1] == graph[row][col])
		{
			visiting(row, col + 1);
		}
		else
		{
			ans++;
			return;
		}
	}
	else if (graph[row][col] == '|')
	{
		if (graph[row+1][col] == graph[row][col])
		{
			visiting(row+1, col);
		}
		else
		{
			ans++;
			return;
		}
	}
}

void solve()
{
	cin >> n >> m;
	memset(visi, false, sizeof(visi));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visiting(i, j);
		}
	}

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}