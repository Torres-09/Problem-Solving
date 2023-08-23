#include<bits/stdc++.h>
using namespace std;
long long fibo[91] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };
int n;


long long result(int num)
{
	if (fibo[num] != 0)
		return fibo[num];
	else
	{
		return fibo[num] = result(num - 1) + result(num - 2);
	}
}

void solve()
{
	cin >> n;

	cout << result(n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}