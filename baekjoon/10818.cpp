#include<iostream>

using namespace std;

int main()
{
	unsigned int number_quntity;
	long int MAX_NUMBER, MIN_NUMBER;
	cin >> number_quntity;
	int* number;
	number = new int[number_quntity];
	for (long int i = 0; i < number_quntity; i++)
	{
		cin >> number[i];
	}
	MAX_NUMBER = number[0];
	MIN_NUMBER = number[0];
	for (long int i = 1; i < number_quntity; i++)
	{
		if (MAX_NUMBER < number[i])
			MAX_NUMBER = number[i];
	}
	for (long int i = 1; i < number_quntity; i++)
	{
		if (MIN_NUMBER > number[i])
			MIN_NUMBER = number[i];
	}
	cout << MIN_NUMBER << " " << MAX_NUMBER << endl;
}
