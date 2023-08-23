#include<iostream>

using namespace std;
int sdo[9][9];

void solve_garo(int n)
{
	int counter_0 = 0;
	int garo = 45;
	int k;
	for (int i = 0; i < 9; i++)
	{
		if (sdo[n][i] == 0) {
			counter_0++; k = i;
		}
		garo = garo - sdo[n][i];
	}
	if (counter_0 > 1)return;
	sdo[n][k] = garo;
	return;
}

void solve_sero(int n)
{
	int counter_0 = 0;
	int sero = 45;
	int k;
	for (int i = 0; i < 9; i++)
	{
		if (sdo[i][n] == 0) {
			counter_0++; k = i;
		}
		sero = sero - sdo[i][n];
	}
	if (counter_0 > 1)return;
	sdo[k][n] = sero;
	return;
}

int main()
{
	

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sdo[i][j];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		solve_sero(i);	
	}
	

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sdo[i][j] << " " ;
		}
		cout << "\n";
	}
	system("pause");
}