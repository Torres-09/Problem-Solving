#include<iostream>

using namespace std;

int main()
{
	int N;
	int X, Y;
	cin >> N;
	int *x = new int[N];
	int *y = new int[N];
	int *z = new int[N];

	for (int i = 0; i < N; i++)
	{
		z[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		x[i] = X;
		y[i] = Y;
	}

	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (x[i] > x[j] && y[i] > y[j]) {
				z[j]++;
			}
			else if (x[i] < x[j] && y[i] < y[j]) {
				z[i]++;
			}
		}
	}
	for (int i = 0; i < N-1; i++)
	{
		cout << z[i] + 1 << " ";
	}
	cout << z[N-1] + 1 << endl;
	system("pause");
}