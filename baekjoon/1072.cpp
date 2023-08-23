// 1을 왜 더 할까? - > if 조건때문에
#include<bits/stdc++.h>
using namespace std;
long long x, y;
long long answer = -1;

void solve()
{
	cin >> x >> y;
	long long k = (y * 100) / x +1;

	if (k >= 100)
	{
		cout << -1 << "\n";
		return;
	}

	long long low = 1;
	long long high = 1000000000;

	while (low <= high)
	{
		long long mid = (low + high) / 2;

		long long temp = (100 * (y + mid)) / (x + mid);

		if (k <= temp)
		{
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << answer << "\n";
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}