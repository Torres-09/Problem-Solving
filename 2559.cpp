#include<bits/stdc++.h>
using namespace std;
long long num[100001];
long long tree[100001];
int n, m;

long long sum(int i)
{
	int result = 0;
	while (i > 0)
	{
		result += tree[i];
		i -= (i&-i);
	}

	return result;
}

void update(int i, int diff)
{
	while (i <= n)
	{
		tree[i] += diff;
		i += (i&-i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int num;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		update(i, num);
	}

	long long answer = INT_MIN;

	for (int i = m; i <= n; i++)
	{
		answer = max(sum(i) - sum(i - m), answer);
	}

	cout << answer;
}