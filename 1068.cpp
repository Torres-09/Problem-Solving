#include<bits/stdc++.h>
using namespace std;
bool visi[51];
vector<vector<int>> tree(50);

void dfs(int vertex)
{
	if (visi[vertex] == true)
		return;

	visi[vertex] = true;

	for (int i = 0; i < tree[vertex].size(); i++)
	{
		dfs(tree[vertex][i]);
	}
}

void solve()
{
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num == -1)
			continue;

		tree[num].push_back(i);
	}

	int k;
	cin >> k;
	dfs(k);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (visi[i] == false && tree[i].size() == 0)
			ans++;
		else
			if (!tree[i].empty())
				if (tree[i][0] == k && tree[i].size() == 1)
					ans++;
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