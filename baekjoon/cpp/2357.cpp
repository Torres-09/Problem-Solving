#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int v[100001];
int mintree[500000];
int maxtree[500000];

int init(int start, int end, int node)
{
	if (start == end) 
		return mintree[node] = v[start];

	int mid = (start + end) / 2;

	return mintree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int maxinit(int start, int end, int node)
{
	if (start == end)
		return maxtree[node] = v[start];

	int mid = (start + end) / 2;

	return maxtree[node] = max(maxinit(start, mid, node * 2), maxinit(mid + 1, end, node * 2 + 1));
}

int findmin(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 1000000000;

	if (left <= start && end <= right)
		return mintree[node];

	int mid = (start + end) / 2;

	return min(findmin(start, mid, node * 2, left, right), findmin(mid + 1, end, node * 2 + 1, left, right));
}

int findmax(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return maxtree[node];

	int mid = (start + end) / 2;

	return max(findmax(start, mid, node * 2, left, right), findmax(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 500000; i++)
	{
		mintree[i] = 1000000000;
		maxtree[i] = 0;
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	init(1, n, 1);
	maxinit(1, n, 1);

	int a, b;

	for(int i =0;i<m;i++)
	{
		cin >> a >> b;
		cout << findmin(1, n, 1, a, b) << " " << findmax(1,n,1,a,b);
		cout << "\n";
	}
}