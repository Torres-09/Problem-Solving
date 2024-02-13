#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int hour, min, sec;
	hour = d / 3600;
	min = (d % 3600) / 60;
	sec = d % 60;

	c += sec;
	b += min + c / 60;
	c = c % 60;
	a += hour + b/60;
	b = b % 60;
	if (a >= 24)
		a = a % 24;
	cout << a << " " << b << " " << c;
}