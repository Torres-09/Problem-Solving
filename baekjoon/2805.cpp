#include<bits/stdc++.h>
using namespace std;

void solve()
{
	vector<int> tree;
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		tree.push_back(number);
	}
	sort(tree.begin(), tree.end());

	if (n == 1)
	{
		cout << tree.front() - m;
		return;
	}

	long long left = 0;
	long long right = tree.back();
	long long mid;
	int answer = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long result = 0;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] - mid > 0)
				result += tree[i] - mid;
		}

		if (result < m)
			right = mid - 1;
		else
		{
			left = mid + 1;
			if (mid > answer)
				answer = mid;
		}

	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}