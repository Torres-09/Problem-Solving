#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int a, b, c;

	cin >> a >> b >> c;

	int hol_count = 0;
	if (a % 2 == 0)
		hol_count++;
	if (b % 2 == 0)
		hol_count++;
	if (c % 2 == 0)
		hol_count++;

	if (hol_count >= 2 == 0)
		cout << "B\n";
	else
		cout << "R\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}