// ¡÷¿Øº“
#include<iostream>
#include<queue>
using namespace std;
queue<long long int> city;
queue<long long int> weight;
long long int result = 0;

long long int n;

int main()
{
	cin >> n;

	long long int number;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> number;
		weight.push(number);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		city.push(number);
	}

	long long int temp = city.front();

	while (!weight.empty())
	{
		city.pop();
		result += temp * weight.front();
		weight.pop();

		if (temp > city.front())
		{
			temp = city.front();
		}
	}

	cout << result << "\n";
} 