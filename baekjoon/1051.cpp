#include<bits/stdc++.h>
using namespace std;
int graph[51][51];
int out_range = 50;

void solve()
{
	int n, m;
	cin >> n >> m;

	
	char c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			graph[i][j] = c - '0';
		}
	}

	int temp = 0;
	int result = 1;
	while (1)
	{
		if (temp > 50)
			break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i + temp >= n || j + temp >= m)
					break;

				if (graph[i][j]==graph[i][j + temp]&& graph[i][j + temp]==graph[i + temp][j]&& graph[i + temp][j]==graph[i + temp][j + temp])
				{
					result = temp;
				}
			}
		}
		temp++;
	}

	cout << pow(result+1,2);
}

int main()
{
	ios::sync_with_stdio(false);

	solve();
}