// ≈‰∏∂≈‰
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int m, n;
int graph[1001][1001];
queue<pair<int, int>> q;
int max_value = 1;
pair<int, int> point;

void BFS()
{
	while (!q.empty())
	{
		point = q.front();
		q.pop();

		if (point.first != 0)
			if (graph[point.first - 1][point.second] == 0)
			{
				q.push({ point.first - 1, point.second });
				graph[point.first - 1][point.second] += graph[point.first][point.second] + 1;
			}

		if (point.first != n - 1)
			if (graph[point.first + 1][point.second] == 0)
			{
				q.push({ point.first + 1,point.second });
				graph[point.first + 1][point.second] += graph[point.first][point.second] + 1;
			}

		if (point.second != 0)

			if (graph[point.first][point.second - 1] == 0)
			{
				q.push({ point.first,point.second - 1 });
				graph[point.first][point.second - 1] += graph[point.first][point.second] + 1;
			}

		if (point.second != m)
			if (graph[point.first][point.second + 1] == 0)
			{
				q.push({ point.first,point.second + 1 });
				graph[point.first][point.second + 1] += graph[point.first][point.second] + 1;
			}
	}
}

int main()
{

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