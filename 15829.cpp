#include<bits/stdc++.h>

using namespace std;
long long mod = 1234567891;
long long r[50];
long long a[50];

void solve()
{
	long long l;
	string s;
	cin >> l >> s;
	for (int i = 0; i < s.length(); i++)
	{
		a[i] = s[i] - 'a' + 1;
	}

	r[0] = 1;
	r[1] = 31;
	for (int i = 2; i < 50; i++)
	{
		r[i] = (r[i - 1] * 31) % mod;
	}

	long long sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += (a[i] * r[i]) % mod;
	}

	cout << sum % mod;
}

int main()
{
	solve();
}