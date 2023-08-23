#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<long long> v;
long long tree[1000005];

long long sum(long long i)
{
	long long result = 0;
	while (i > 0)
	{
		result += tree[i];
		i -= (i&-i);
	}
	return result;
}

void update(long long i, long long diff)
{
	while (i <= n)
	{
		tree[i] += diff;
		i += (i&-i);
	}
}

void solve()
{
	cin >> n >> m >> k;

	long long num;
	v.push_back(0);
	for (long long i = 1; i <= n; i++)
	{
		cin >> num;
		v.push_back(num);
		update(i, num);
	}

	int cmd;
	while ((m + k) != 0)
	{
		cin >> cmd;
		if (cmd == 1)
		{
			long long num1, num2;
			cin >> num1 >> num2;
			long long diff = num2 - v[num1];
			v[num1] = num2;
			update(num1, diff);
			m--;
		}
		else if (cmd == 2)
		{
			long long num1, num2;
			cin >> num1 >> num2;
			cout << sum(num2) - sum(num1-1) << "\n";
			k--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}