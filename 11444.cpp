#include<iostream>
using namespace std;
long long n;
long long fibo[18] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };
long long c = 1000000007;

long long solution(long long size)
{
	if (size <= 17)
	{
		return fibo[size];
	}

	long long result = (solution(size - 1) % c + solution(size - 2) % c) % c;

	return result;
}

int main()
{
	cin >> n;

	cout << solution(n);
}