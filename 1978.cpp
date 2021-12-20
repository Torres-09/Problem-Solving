#include<iostream>

using namespace std;

bool prime_number(int number)
{
	if (number == 2)
		return true;

	if (number % 2 == 0||number==1)
		return false;
	else
	{
		for (int i = 3; i <= number / 2; i++)
		{
			if (number%i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	int N;
	cin >> N;

	int prime_number_result = 0;
	while (N--)
	{
		int number;
		cin >> number;
		if (prime_number(number) == true) {
			prime_number_result++;
		}
	}
	cout << prime_number_result;
	cout << endl;
}