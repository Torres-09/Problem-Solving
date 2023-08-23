#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int base =0;
int now =0;
int answer = 0;
int result = 0;

void solve()
{
	int num;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	result += v[base];
	while (base <= now && now < n && base<n)
	{
		if (result == m)
		{
			answer++;
			now++;

			if (now == n)
				break;

			result += v[now];
		}
		else if (result < m)
		{
			now++;

			if (now == n)
				break;

			result += v[now];
		}
		else if (result > m)
		{
			result -= v[base];
			base++;
		}

		if (base > now)
		{
			now = base;
			result = v[base];
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}