#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a(4);
	vector<int> b(4);

	for (int i =0;i<4;i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
	}

	int sum1 =0,  sum2 = 0;
	for (int i = 0; i < 4; i++)
	{
		sum1 += a[i];
		sum2 += b[i];
	}

	cout << max(sum1,sum2);
}