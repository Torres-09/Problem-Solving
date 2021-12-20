#include<iostream>

using namespace std;

int main()
{
	int number[9];
	int MAX_NUMBER;
	int MAX_NUMBER_INDEX;

	for (int i = 0; i < 9; i++)
	{
		cin >> number[i];
	}
	MAX_NUMBER = number[0];
	MAX_NUMBER_INDEX = 1;
	for (int i = 1; i < 9; i++)
	{
		if (MAX_NUMBER < number[i])
		{
			MAX_NUMBER = number[i];
			MAX_NUMBER_INDEX = i+1;
		}
	}
	cout << MAX_NUMBER << endl << MAX_NUMBER_INDEX;
}