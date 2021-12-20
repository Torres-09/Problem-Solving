#include<iostream>

using namespace std;

int main()
{
	int a, b;
	int c, d;
	int f, g;
	int h, i;
	cin >> a >> b >> c >> d >> f >> g;
	if (a == c)
		h = f;
	else if (a == f)
		h = c;
	else
		h = a;

	if (b == d)
		i = g;
	else if (b == g)
		i = d;
	else
		i = b;
	
	cout << h << " " << i << "\n";
	system("pause");
}