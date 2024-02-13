#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long answer;
vector<bool> check;

void solve()
{
	cin >> n >> m;
	answer = m - n + 1;
	check.assign(m - n + 1, false);

	long long i = 2;
	while (i*i <= m) {
		long long quotient = n / (i*i);

		if (n % (i*i) != 0)
			quotient += 1;

		while (quotient * (i*i) <= m) {
			if (check[quotient * (i*i) - n] == false)
			{
				check[quotient * (i*i) - n] = true;
				answer -= 1;
			}
			quotient += 1;
		}

		i += 1;
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