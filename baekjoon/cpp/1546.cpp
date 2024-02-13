#include<iostream>

using namespace std;

int main()
{
	int N;//과목 개수
	cin >> N;
	int* arr;
	arr = new int[N];
	int MAX_NUMBER;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	MAX_NUMBER = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (MAX_NUMBER < arr[i])
		{
			MAX_NUMBER = arr[i];
		}
	}
	double AVERAGE = 0;
	for (int i = 0; i < N; i++)
	{
		AVERAGE += arr[i];
	}
	AVERAGE = (AVERAGE * 100 / MAX_NUMBER) / N;
	cout << AVERAGE << endl;
	system("pause");
}