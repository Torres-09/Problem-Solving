#include<bits/stdc++.h>
using namespace std;


void solve()
{
	long long n, k;
	cin >> n >> k;
	
	long long left = 1;
	long long right = n * n;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long count = 0;
		for (int i = 1; i <= n; i++)
		{
			count += min(mid / i, n);
		}

		if (count >= k)
		{
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}