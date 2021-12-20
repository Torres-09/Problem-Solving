#include<iostream>

using namespace std;

bool Hansu(int num)
{
	if (num < 100)
		return true;
	else if (num == 1000)
		return false;
	else if (num >= 100 && num < 1000)
	{
		int First_num = num / 100;
		int Second_num = (num / 10) % 10;
		int Third_num = num % 10;
		if ((Third_num - Second_num) == (Second_num - First_num))
			return true;
		else
			return false;
	}
}

int main()
{
	int N;
	cin >> N;
	int number = 0;

	for (int i = 1; i <= N; i++)
	{
		if (Hansu(i))
			number++;
	}
	cout << number << endl;
}

//111 123 135 147 159 210