// 구간 합 구하기 4
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int tree[100001];
int segment_tree[400005];

int mk_segment_tree(int start, int end, int node)
{
	if (start == end)
		return	segment_tree[node] = tree[start];

	int mid = (start + end) / 2;

	return segment_tree[node]  =  mk_segment_tree(start, mid, node * 2) + mk_segment_tree(mid + 1, end, node *2 + 1);
}

int find_sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return segment_tree[node];

	int mid = (start + end) / 2;

	return find_sum(start, mid, node * 2, left, right) + find_sum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i];
	}

	mk_segment_tree(1, n, 1);

	int left, right;

	for (int i = 0; i < m; i++)
	{
		cin >> left >> right;
		cout << find_sum(1,n,1, left, right) << "\n";
	}
}