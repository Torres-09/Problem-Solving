//�÷��̵� ����
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
			// 0���� üũ�ϴ� �� ����
			if (i == j)
				graph[i][j] = 0;
			else
				//LONG_MAX �� �ϸ� �����÷ο� �߻��ؼ� �� �ȴ�.
				graph[i][j] = INT_MAX;
			
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = min(c, graph[a][b]);
	}

	for (int k = 1; k <= n; k++)	// ������
	{
		for (int i = 1; i <= n; i++)	// �����
		{
			for (int j = 1; j <= n; j++)	// ������
			{
				//LONG_MAX �ϸ� ���⼭ �����÷ο� �߻��Ѵ�.
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