#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b, c, d, e;
	a = pow(n % 10, 5);
	n /= 10;
	b = pow(n % 10, 5);
	n /= 10;
	c = pow(n % 10, 5);
	n /= 10;
	d = pow(n % 10, 5);
	n /= 10;
	e = pow(n % 10, 5);
	cout << a + b + c + d + e;
}