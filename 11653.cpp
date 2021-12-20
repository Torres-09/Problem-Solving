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
	int N;
	cin >> N;
	int i = 2;
	while (1)
	{
		if (N == 1) {
			
			return 0;
		}
		else if (N == 2) {
			cout << "2" << endl;
			
			return 0;
		}

		if (N%i == 0) {
			cout << i << endl;
			N = N / i;
		}
		else
		{
			i = i + 1;
		}
	}
	
}