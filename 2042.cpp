// 구간 합 구하기
#include<iostream>
#include<algorithm>
using namespace std;
long long int n, m, k;
long long int segment_tree[4000010];
long long int tree[1000010];

long long int mk_segment_tree(int start, int end, int node)
{
	if (start == end)
		return	segment_tree[node] = tree[start];

	int mid = (start + end) / 2;

	return segment_tree[node] = mk_segment_tree(start, mid, node * 2) + mk_segment_tree(mid + 1, end, node * 2 + 1);
}

long long int find_sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return segment_tree[node];

	int mid = (start + end) / 2;

	return find_sum(start, mid, node * 2, left, right) + find_sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long int diff)
{
	if (index < start || index > end) return;

	segment_tree[node] += diff;
	if (start == end)return;
	int mid = (start + end) / 2;
	
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i];
	}

	mk_segment_tree(1, n, 1);

	long long int a, b, c;
	long long int diff;

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			diff = c - tree[b];
			tree[b] = c;
			update(1, n, 1, b, diff);
		}
		else if (a == 2)
			cout << find_sum(1, n, 1, b, c) << "\n";
	}
}