//플로이드 워셜
#include<bits/stdc++.h>
using namespace std;
int n, m;
long long graph[101][101];
long long a, b, c;

void solve()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// 0으로 체크하는 거 주의
			if (i == j)
				graph[i][j] = 0;
			else
				//LONG_MAX 로 하면 오버플로우 발생해서 안 된다.
				graph[i][j] = INT_MAX;
			
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = min(c, graph[a][b]);
	}

	for (int k = 1; k <= n; k++)	// 경유지
	{
		for (int i = 1; i <= n; i++)	// 출발지
		{
			for (int j = 1; j <= n; j++)	// 도착지
			{
				//LONG_MAX 하면 여기서 오버플로우 발생한다.
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INT_MAX)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}