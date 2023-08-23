#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int N;
	int F;
	cin >> N >> F;
	int Num[100];
	for (int i = 0; i < 100; i++)
	{
		Num[i] = N - (N % 100) + i;
	}

	int check;

	for (int i = 0; i < 100; i++)
	{
		if (Num[i] % F == 0)
		{
			check = i;
			break;
		}
	}

	cout  << setfill('0') << setw(2) << check << "\n";
	system("pause");
}