#include<bits/stdc++.h>
using namespace std;
long long tree[1000001];
long long segment_tree[4000005];
long long modul = 1000000007;

long long mk_segment_tree(long long start, long long end, long long node)
{
	if (start == end)
		return segment_tree[node] = tree[start];

	long long mid = (start + end) / 2;

	return segment_tree[node] = (mk_segment_tree(start, mid, node * 2) * mk_segment_tree(mid + 1, end, node * 2 + 1)) % modul;
}

long long find_mul(long long start, long long end, long long node, long long left, long long right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return segment_tree[node];

	long long mid = (start + end) / 2;

	return (find_mul(start, mid, node * 2, left, right) * find_mul(mid + 1, end, node * 2 + 1, left, right)) % modul;
}

long long updata(int start, int end, int node, int index, int num)
{
	if (index < start || end < index)
		return segment_tree[node];

	if (start == end)
		return segment_tree[node] = num;

	int mid = (start + end) / 2;

	return segment_tree[node] = (updata(start, mid, node * 2, index, num) * updata(mid + 1, end, node * 2 + 1, index, num)) % modul;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	int number;
	for (int i = 1; i <= n; i++)
	{
		cin >> number;
		tree[i] = number;
	}

	mk_segment_tree(1, n, 1);
	int a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			updata(1, n, 1, b, c);
		}
		if (a == 2)
		{
			cout << find_mul(1, n, 1, b, c) << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}