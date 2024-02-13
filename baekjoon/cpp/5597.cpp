#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool a[31] = { false };
	int n;
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		a[n] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (a[i] == false)
			cout << i << "\n";
	}
}