#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l, o;
	cin >> l >> o;

	int n[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> n[i];
	}

	int temp = l * o;
	for (int i = 0; i < 5; i++)
	{
		cout << n[i] - temp << " ";
	}
}