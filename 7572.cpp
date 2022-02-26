#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	n += (2400 - 2013);

	char a[12] = { 'A' };
	

	for (int i = 1; i < 12; i++)
	{
		a[i] = a[0] + i;
	}

	int c = (n + 5) % 12;
	int b = (n + 9) % 10;
	cout << a[c] << b;
}

int main()
{
	solve();
}