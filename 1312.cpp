#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;

	a = a % b;

	vector<int> v;
	while (1)
	{
		if (a / b < 1)
		{
			a *= 10;
		}
		else
		{
			if (!v.empty())
			{
				if (v.front() == a / b)
					break;
			}

			v.push_back(a / b);
			a %= b;
			a *= 10;

			if (a == 0)
				break;
		}
	}

	if (v.size() == 0)
	{
		cout << "0";
	}
	else if (v.size() == 1)
	{
		cout << v[0];
	}
	else
	{
		int ans = c % v.size();
		cout << v[ans - 1];
	}
}