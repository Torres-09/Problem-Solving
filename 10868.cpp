#include<bits/stdc++.h>
using namespace std;
long long tree[100001];
long long segement_tree[400005];

long long mk_segment_tree(int start, int end, int node)
{
	if (start == end)
		return segement_tree[node] = tree[start];

	int mid = (start + end) / 2;

	return segement_tree[node] = min(mk_segment_tree(start, mid, node * 2), mk_segment_tree(mid + 1, end, node * 2 + 1));
}

long long find_min(int start, int end, int node, int left, int right)
{
	
	if (left>end||right<start)
		return LONG_MAX;

	if (left <= start && end <= right)
		return segement_tree[node];

	int mid = (start + end) / 2;

	return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

void solve()
{
	int n, m;
	cin >> n >> m;

	
	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i];
	}

	mk_segment_tree(1, n, 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << find_min(1, n, 1, a, b) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}