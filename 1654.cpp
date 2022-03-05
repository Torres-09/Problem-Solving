#include<bits/stdc++.h>
using namespace std;
vector<int> len;
int n, k;
long long answer = 0;

void solve()
{
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		len.push_back(number);
	}
	sort(len.begin(), len.end());

	long long left = 1;
	long long right = len.back();
	long long mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long count = 0;
		for (int i = 0; i < n; i++)
		{
			count += len[i] / mid;
		}

		if (count >= k)
		{
			left = mid + 1;
			if (answer < mid) answer = mid;
		}
		else
		{
			right = mid - 1;
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