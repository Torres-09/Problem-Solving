#include<iostream>
#include<cmath>


using namespace std;

int main()
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0)
			break;

		if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}
}