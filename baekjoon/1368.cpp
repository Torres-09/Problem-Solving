#include<bits/stdc++.h>
using namespace std;
int n;
tuple<int, int, int> edge[100005];
vector<int> g(1000);

int find(int c) {
	if (g[c] == 0)return c;
	return g[c] = find(g[c]);
}

void union_func(int v, int u) {
	g[find(v)] = find(u);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		edge[index++] = { cost,i,n + 1 };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i >= j)continue;
			edge[index++] = { cost,i,j };
		}
	}
	sort(edge, edge + index);

	int answer = 0;
	int cnt=0;
	for (int i = 0; i < index; i++) {
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (find(a) == find(b))continue;
		union_func(a, b);
		answer += cost;
		cnt++;
		if (cnt == n)break;
	}
	cout << answer;
}