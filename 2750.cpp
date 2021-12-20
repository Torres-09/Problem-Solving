#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* number = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}
	int N_temp = N;

	while (N_temp--)
	{
		for (int i = 0; i < N_temp; i++)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << number[i] << "\n";
	}
	system("pause");
}