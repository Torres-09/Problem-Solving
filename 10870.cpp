#include<iostream>

using namespace std;

int Fibo(int number)
{
	if (number == 0)
	{
		return 0;
	}
	else if (number == 1)
	{
		return 1;
	}
	else
	{
		return Fibo(number - 1) + Fibo(number - 2);
	}
}
int main()
{
	int N;
	cin >> N;
	cout << Fibo(N)<<endl;
	system("pause");

}