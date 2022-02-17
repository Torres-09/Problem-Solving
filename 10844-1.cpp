#include<iostream>
using namespace std;
int stair[10][101];

int main()
{
	int n;
	cin >> n;
	
	stair[0][1] = 0;
	for (int i = 1; i <= 9; i++)
	{
		stair[i][1] = 1;
	}

	for (int i = 2; i <= 100; i++)
	{
		stair[0][i] += stair[1][i - 1] % 1000000000;
		for (int j = 1; j <= 8; j++)
		{
			stair[j][i] += (stair[j - 1][i - 1] + stair[j + 1][i - 1]) % 1000000000;
		}
		stair[9][i] += stair[8][i - 1] % 1000000000;
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum = (sum + stair[i][n]) % 1000000000;
	}

	cout << sum;
}