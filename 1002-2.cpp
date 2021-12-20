#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{

	int T;
	cin >> T;
	while (T--)
	{
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		if (x1 == x2&&y1 == y2&&r1 == r2) {
			cout << "-1\n";
		}
		else if (distance > pow(r1 + r2, 2) || distance < pow(abs(r1 - r2), 2))
		{
			cout << "0\n";
		}
		else if (distance == pow(r1 + r2, 2) || distance == pow(abs(r1 - r2), 2))
		{
			cout << "1\n";
		}
		else
			cout << "2\n";
	}
	system("pause");
}