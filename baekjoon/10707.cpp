#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	if (e >= c)
	{
		b = b + (e - c) * d;
	}

	cout << min(a * e, b);
}