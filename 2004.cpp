#include<bits/stdc++.h>
using namespace std;

long long two_counter(long long number)
{
	long long result = 0;
	long long temp = 1;

	for (long long i = 2;temp!=0; i *= 2)
	{
		temp = number / i;
		result += temp;
	}

	return result;
}

long long five_counter(long long number)
{
	long long result = 0;
	long long temp = 1;

	for (long long i = 5; temp != 0; i *= 5)
	{
		temp = number / i;
		result += temp;
	}

	return result;
}

void solve()
{
	long long n, m;
	cin >> n >> m;

	cout << min(five_counter(n) - (five_counter(m) + five_counter(n-m)),two_counter(n) - (two_counter(m)+two_counter(n-m)));
}

int main()
{
	solve();
}