#include<iostream>
using namespace std;
long long a, b, c;

int solution(long long  x, long long  size)
{
	if (size == 1)
	{
		return (x % c);
	}

	long long result = solution(x, size / 2);
	
	if (size % 2 == 0)
		return result % c *result %c;
	else
		return result % c * result % c * (a%c) % c;
	
}

int main()
{
	cin >> a >> b >> c;
	cout << solution(a, b);
}