#include<iostream>

using namespace std;

int main()
{
	int arr[10];
	int Diffrent = 10;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	int arr_div_42[10];
	for (int i = 0; i < 10; i++)
	{
		arr_div_42[i] = arr[i] % 42;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr_div_42[i] == arr_div_42[j])
			{
				Diffrent--;
				break;
			}
		}
	}
	cout << Diffrent << endl;
}