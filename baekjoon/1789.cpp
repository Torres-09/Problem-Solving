#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int s;
	cin >> s;


	long long int ss = 0;
	long long int i = 1;
	for (i = sqrt(s);ss <= s; i++)
	{
		ss = (i * (i + 1)) / 2;
	}

	cout << i - 2;
}