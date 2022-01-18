// 구간트리, 세그먼트 트리
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int v[100001];
int mintree[400010];
int maxtree[400010];

int min_segment_tree(int start, int end, int node)
{
	if (start == end)
		return mintree[node] = v[start];

	int mid = (start + end) / 2;

	return mintree[node] = min(min_segment_tree(start, mid, node * 2), min_segment_tree(mid + 1, end, node * 2 + 1));
}

int max_segment_tree(int start, int end, int node)
{
	if (start == end)
		return maxtree[node] = v[start];

	int mid = (start + end) / 2;

	return maxtree[node] = max(max_segment_tree(start, mid, node * 2), max_segment_tree(mid + 1, end, node * 2 + 1));
}

int find_min(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return INT_MAX;

	if (left <= start && end <= right)
		return mintree[node];

	int mid = (start + end) / 2;

	return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

int find_max(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return maxtree[node];

	int mid = (start + end) / 2;

	return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 500000; i++)
	{
		mintree[i] = INT_MAX;
		maxtree[i] = 0;
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	min_segment_tree(1, n, 1);
	max_segment_tree(1, n, 1);

	int a, b;

	for(int i =0;i<m;i++)
	{
		cin >> a >> b;
		cout << find_min(1, n, 1, a, b) << " " << find_max(1,n,1,a,b);
		cout << "\n";
	}
}