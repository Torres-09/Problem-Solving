#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;


	vector<int > v;
	int number = 1;
	int count = 0;
	int count_2 = 0;
	while (1)
	{
		if (count_2 == 1001)
			break;

		v.push_back(number);
		count++;
		count_2++;

		if (count == number)
		{
			number++;
			count = 0;
		}
	}

	int sum = 0;
	for (int i = a -1 ; i <= b - 1; i++)
	{
		sum += v[i];
	}

	cout << sum;
}

int main()
{
	solve();
}