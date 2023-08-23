// ¿Àºì ½Ã°è
#include<iostream>
using namespace std;

int main()
{
	int a, b,c;
	cin >> a >> b >> c;


	int hour, min;
	hour = c / 60;
	min = c % 60;

	a += hour;
	b += min;
	a += b / 60;
	b %= 60;
	a %= 24;
	cout << a << " "<< b;

}
