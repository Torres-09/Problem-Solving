#include<iostream>

using namespace std;

int main()
{
	int x = 1;
	int y = 1;	//  x/y
	int counter = 1;
	int X;
	cin >> X;

	while (1) {
		if (x == 1)
		{
			y++;
			counter++;
			if (counter == X)
				break;
		}
		while (y != 1) {
			x++; y--;
			counter++;
			if (counter == X)
				break;
		}

		if (counter == X)
			break;

		if (y == 1)
		{
			x++;
			counter++;
			if (counter == X)
				break;
		}
		while (x != 1) {
			x--; y++;
			counter++;
			if (counter == X)
				break;
		}
		if (counter == X)
			break;
	}


	cout << x << "\/" << y << endl;
	system("pause");
}