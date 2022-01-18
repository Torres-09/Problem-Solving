//°Ë¹®
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int v[101];
int answer[5000];


int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

int main()
{
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v, v + n);

	int result;
	result = v[1] - v[0];
	for (int i = 2; i < n; i++)
	{
		result = gcd(result, v[i] - v[i - 1]);
	}

	for (int i = 1; i*i <= result; i++)
	{
		if (result % i == 0)
		{
			answer[count] = i;
			count++;
			if (i != result / i)
			{
				answer[count] = result / i;
				count++;
			}
		}
	}

	sort(answer, answer + 5000);
	for (int i = 0; i < 5000; i++)
	{
		if (answer[i] != 0 && answer[i] != 1)
			cout << answer[i] << " ";
	}
}