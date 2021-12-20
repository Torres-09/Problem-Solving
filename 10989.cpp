#include<iostream>

using namespace std;

int main()
{
	int number[10001] = { 0 };
	int N;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		number[num]++;
	}
	for (int i = 1; i <= 10000;)
	{
		if (number[i] != 0)
		{
			cout << i << "\n";
			number[i]--;
		}
		else if(number[i] ==0)
		{
			i++;
		}
	}
	system("pause");
}