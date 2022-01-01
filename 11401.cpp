#include<iostream>
using namespace std;
long long n, k;
long long c = 1000000007;

long long solution(long long x, long long exp)
{
	if (exp == 1)
		return x % c;

	long long half = solution(x, exp / 2);

	if (exp % 2 == 0)
		return half * half % c;
	else
		return (half * half % c) * x % c;
}

long long fac(long long size)
{
	long long result = 1;

	while (size > 1)
	{
		result = (result * size) % c;
		size--;
	}

	return result;
}

int main()
{
	cin >> n >> k;

	// n!
	long long number = fac(n);

	long long denom = fac(k) * fac(n - k) % c;

	cout << number * solution(denom, c - 2) % c;

}