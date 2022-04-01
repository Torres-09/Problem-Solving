#include<bits/stdc++.h>
using namespace std;
long long tree[1000001];
long long segment_tree[4000005];
long long lazy[4000005];

long long mk_segment_tree(long long start, long long end, long long node)
{
	if (start == end)
		segment_tree[node] = tree[start];

	long long mid = (start + end)/2;

	return segment_tree[node] = mk_segment_tree(start, mid, node) + mk_segment_tree(mid + 1, end, node);
}

void update_lazy(long long start, long long end, long long node)
{
	if (lazy[node] != 0) {
		segment_tree[node] += (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(long long start, long long end, long long node, long long left, long long right, long long num)
{
	update_lazy(start, end, node);

	if (left > end || right < start) return;

	if (left <= start && end <= right)
	{
		segment_tree[node] += (end - start + 1) * num;
		if (start != end)
		{
			lazy[node * 2] += num;
			lazy[node * 2 + 1] += num;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(start, mid, node * 2, left, right, num);
	update_range(mid + 1, end, node * 2 + 1, left, right, num);
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

long long find_sum(long long start, long long end, long long node, long long left, long long right)
{
	update_lazy(start, end, node);

	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return segment_tree[node];

	int mid = (start + end) / 2;

	return find_sum(start, mid, node * 2, left, right) + find_sum(mid + 1, end, node * 2 + 1, left, right);
}

void solve()
{
	long long n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i];
	}

	mk_segment_tree(1, n, 1);

	long long a, b, c, d;

	for (int i = 0; i < m+k; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update_range(1,n,1,b,c,d);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			cout << find_sum(1, n, 1, b, c) << "\n";
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