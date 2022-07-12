// LCA 2 ( logn 시간복잡도로 구하기 )
#include<bits/stdc++.h>
using namespace std;
int n, m;
int a, b;
int parent[18][100001];
int depth[100001];
vector<int> v[100001];

void DFS(int cur, int dep, int par)
{
	if (depth[cur] != -1)
		return;

	depth[cur] = dep;
	parent[0][cur] = par;

	for (int i = 0; i < v[cur].size(); i++)
	{
		DFS(v[cur][i], dep + 1, cur);
	}
}

void solve()
{
	cin >> n;

	parent[0][1] = 0;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(depth, -1, sizeof(depth));
	DFS(1, 0, 0);
	
	// 점핑 테이블 생성
	for (int i = 1; i <= 17; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	int m;
	cin >> m;

	while (m--)
	{
		cin >> a >> b;
		// a,b 의 LCA 구하여 출력

		int diff;

		if (depth[a] <= depth[b]) swap(a, b);
		diff = depth[a] - depth[b];

		int ans;
		for (int i = 0; diff > 0; i++)
		{
			if (diff % 2 == 1)
				a = parent[i][a];
			diff = diff >> 1;
		}

		if (a != b)
		{
			for (int i = 17; i >=0; i--)
			{
				if (parent[i][a] != 0 && parent[i][a] != parent[i][b])
				{
					a = parent[i][a];
					b = parent[i][b];
				}
			}

			a = parent[0][a];
		}

		cout << a << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}