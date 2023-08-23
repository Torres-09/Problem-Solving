#include<bits/stdc++.h>
using namespace std;
int n, r, c;
int ans = 0;

void check(int n, int r, int c)
{
	if (n == 0)
		return;

	int size = pow(2, n);
	int half = size / 2;

	if (r / half == 0 && c / half == 0)
	{
		ans += pow(half, 2) * 0;
		check(n-1,r%half,c%half);
	}
	else if (r / half == 0 && c / half == 1)
	{
		ans += pow(half, 2) * 1;
		check(n - 1, r%half, c%half);
	}
	else if (r / half == 1 && c / half == 0)
	{
		ans += pow(half, 2) * 2;
		check(n - 1, r%half, c%half);
	}
	else
	{
		ans += pow(half, 2) * 3;
		check(n - 1, r%half, c%half);
	}
}

void solve()
{
	cin >> n >> r >> c;
	check(n,r,c);
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}