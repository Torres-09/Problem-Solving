#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int temp1;
	int temp2;
	if (a%c != 0)
		temp1 = a / c + 1;
	else
		temp1 = a / c;

	if (b%d != 0)
		temp2 = b / d + 1;
	else
		temp2 = b / d;

	cout << l - max(temp1, temp2);
}