#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cou = 0;
	int number;
	for (int i = 0; i < 5; i++)
	{
		cin >> number;
		if (number == n)
			cou++;
	}
	cout << cou;
}