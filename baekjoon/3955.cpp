#include<bits/stdc++.h>
using namespace std;
long long t;
long long k, c;
long long MAX = 1000000000;

long long gcd(long long num1, long long num2)
{
	long long temp;

	if (num1 < num2)
		swap(num1, num2);

	while (num2 != 0)
	{
		temp = num1;
		num1 = num2;
		num2 = temp % num2;
	}

	return num1;
}

void solve()
{
	cin >> k >> c;

	if (k == 1 && c == 1)
	{
		cout << 2 << "\n";
		return;
	}
	else if (c == 1)
	{
		if (k + 1 > MAX)
		{
			cout << "IMPOSSIBLE\n";
			return;
		}

		cout << k + 1 << "\n";
		return;
	}

	if(gcd(k,c) != 1)
		cout << "IMPOSSIBLE\n";
	else
	{
		long long q, r1, r2, r, s1, s2, s, t1, t2, t;
		r1 = k, r2 = c;
		s1 = 1, s2 = 0, t1 = 0, t2 = 1;
		while (1)
		{
			q = r1 / r2;
			r = r1 - (q*r2);
			s = s1 - (q*s2);
			t = t1 - (q*t2);

			if (r == 0)
			{
				if (t2 > 0)
				{
					if (t2 > MAX)
					{
						cout << "IMPOSSIBLE\n";
						break;
					}
					cout <<  t2 << "\n";
					break;
				}
				else if (t2 <= 0)
				{
					cout << t2 + k << "\n";
					break;
				}
			}

			r1 = r2;
			r2 = r;
			s1 = s2;
			s2 = s;
			t1 = t2;
			t2 = t;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		solve();
	}
}