#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 8; i++)
	{
		if (i == 7)
		{
			cout << "ascending";
			return 0;
		}

		if (a[i] == i + 1)
			continue;
		else
			break;
	}

	for (int i = 0; i < 8; i++)
	{
		if (i == 7)
		{
			cout << "descending";
			return 0;
		}

		if (a[i] == 8-i)
			continue;
		else
			break;
	}
	
	cout << "mixed";
}