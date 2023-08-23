#include<bits/stdc++.h>
using namespace std;
int n, m;
int graph[9][9];
vector<pair<int, int>> zero;
int ans = 0;
bool Visit[9][9];
queue<pair<int, int>> virus;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int wall_count = 0;

void BFS()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Visit[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 2)
				virus.push({ i,j });
		}
	}
	int virus_count = virus.size();

	while (!virus.empty())
	{
		pair<int, int> point = virus.front();
		virus.pop();

		for (int i = 0; i < 4; i++)
		{
			if (point.first + dx[i] < n && point.second + dy[i] < m && point.first + dx[i] >= 0 && point.second + dy[i]>=0)
			{
				if (graph[point.first + dx[i]][point.second + dy[i]] == 0 && Visit[point.first + dx[i]][point.second + dy[i]] == false)
				{
					Visit[point.first + dx[i]][point.second + dy[i]] = true;
					virus_count++;
					virus.push({ point.first + dx[i],point.second + dy[i] });
				}
			}
			
		}
	}

	ans = max(ans, n*m - wall_count - 3 - virus_count);
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 0)
				zero.push_back({ i,j });
			else if(graph[i][j]==1)
				wall_count++;
		}
	}

	for (int i = 0; i < zero.size(); i++)
	{
		for (int j = i + 1; j < zero.size(); j++)
		{
			for (int k = j + 1; k < zero.size(); k++)
			{
				graph[zero[i].first][zero[i].second] = 1;
				graph[zero[j].first][zero[j].second] = 1;
				graph[zero[k].first][zero[k].second] = 1;

				BFS();

				graph[zero[i].first][zero[i].second] = 0;
				graph[zero[j].first][zero[j].second] = 0;
				graph[zero[k].first][zero[k].second] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	cout << ans;
}