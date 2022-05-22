#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	for (int i = 1;true; i++)
	{
		int ans = 0;

		for (int j = 0; j < 5; j++)
		{
			if (i%a[j] == 0)
				ans++;

			if (ans >= 3)
			{
				cout << i;
				return 0;
			}
		}
	}
}