#include<bits/stdc++.h>
using namespace std;
int n;

void solve()
{
	cin >> n;

	int five_count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i % 125 == 0)
			five_count += 3;
		else if (i % 25 == 0)
			five_count += 2;
		else if (i % 5 == 0)
			five_count += 1;
	}

	if (n < 5)
		cout << 0;
	else
		cout << five_count;
}

int main()
{
	solve();
}