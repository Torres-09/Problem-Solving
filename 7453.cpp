#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[4001], b[4001], c[4001], d[4001];
vector<long long> e;
vector<long long> f;

void solve()
{
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}


	for (long long i = 0; i < n; i++)
	{
		for (long long j = 0; j < n; j++)
		{
			e.push_back(a[i] + b[j]);
			f.push_back(c[i] + d[j]);
		}
	}

	sort(e.begin(), e.end());
	sort(f.begin(), f.end());

	long long answer = 0;

	for (long long i = 0; i < e.size(); i++)
	{
		answer += upper_bound(f.begin(), f.end(), -1 * e[i]) - lower_bound(f.begin(), f.end(), -1 * e[i]);
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}