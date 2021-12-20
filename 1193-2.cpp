#include<iostream>

using namespace std;

int main()
{
	int X;
	cin >> X;
	
	int N = 1;
	while (1)
	{
		if (X - N <= 0)
			break;
		X = X - N;
		N++;
	}

	if (N % 2 == 0)
	{
		cout << X << "\/" << N - X + 1 <<endl;
	}
	else
	{
		cout << N - X +1 << "\/" << X <<endl;
	}
	system("pause");
}