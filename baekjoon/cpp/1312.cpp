#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a = a % b;

	int ans;
	
	while (c--)
	{
		a *= 10;
		ans = a / b;
		a %= b;
	}

	cout << ans;
}