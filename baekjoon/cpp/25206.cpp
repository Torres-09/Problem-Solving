#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	double a;
	string c;
	double ans = 0;
	double total = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> s >> a >> c;

		if (c == "A+")
		{
			ans += a * 4.5;
			total += a;
		}
		else if (c == "A0")
		{
			ans += a * 4.0;
			total += a;
		}
		else if (c == "B+")
		{
			ans += a * 3.5;
			total += a;
		}
		else if (c == "B0")
		{
			ans += a * 3.0;
			total += a;
		}
		else if (c == "C+")
		{
			ans += a * 2.5;
			total += a;
		}
		else if (c == "C0")
		{
			ans += a * 2.0;
			total += a;
		}
		else if (c == "D+")
		{
			ans += a * 1.5;
			total += a;
		}
		else if (c == "D0")
		{
			ans += a * 1.0;
			total += a;
		}
		else if (c == "F")
		{
			total += a;
		}
	}

	cout << fixed << setprecision(6) << ans / total;
}