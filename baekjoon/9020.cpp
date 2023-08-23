#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	vector<int> number;
	for (int i = 0; i < 10001; i++)
	{
		number.push_back(i);
	}

	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (number[i] == 0)
			continue;

		for (int j = i*i; j <= 10000; j += i)
		{
			number[j] = 0;
		}
	}
	number[1] = 0;
	int T;
	cin >> T;

	while (T--)
	{

		int n;
		cin >> n;

		for (int i = n / 2; i < n; i++)
		{
			if(number[i]!=0)
				if (number[n - number[i]] != 0)
				{
					cout << n - i << " " << i << "\n";
					break;
				}
		}
	}


}
