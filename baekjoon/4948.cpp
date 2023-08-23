#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	vector<int> number;
	for (int i = 0; i < 246913; i++)
	{
		number.push_back(i);
	}

	for (int i = 2; i <= sqrt(246912); i++)
	{
		if (number[i] == 0)
			continue;

		for (int j = i*i; j <= 246912; j += i)
		{
			number[j] = 0;
		}
	}
	number[1] = 0;

	int N;
	int result = 0;
	cin >> N;
	while (N)
	{
		for (int i = N+1; i <= 2 * N; i++)
		{
			if (number[i] != 0)
			{
				result++;
			}
		}
		cout << result << "\n";
		result = 0;
		cin >> N;
	}
}
	