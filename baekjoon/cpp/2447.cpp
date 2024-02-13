#include<iostream>
#include<cstring>
#include<string>

using namespace std;

void Making_star(int row, int col, int N)
{
	if ((row / N) % 3 == 1 && (col / N) % 3 == 1)
		cout << ' ';
	else
	{
		if (N  == 1)
			cout << '*';
		else
			Making_star(row, col, N / 3);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Making_star(i, j, N);
		}
		cout << "\n";
	}
	system("pause");
}