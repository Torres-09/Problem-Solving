#include<iostream>

using namespace std;

bool prime_number(int number)
{
	if (number == 2)
		return true;

	if (number % 2 == 0 || number == 1)
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
	int M, N;
	int firstprime_number = -1;
	bool first_prime_number = false;
	int sum = 0;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (prime_number(i)) {
			sum = sum + i;
			if (first_prime_number == false)
			{
				firstprime_number = i;
				first_prime_number = true;
			}
		}
		
	}
	if (sum == 0)
		cout << firstprime_number;
	else
	{
		cout << sum << endl << firstprime_number << endl;
	}
	
}