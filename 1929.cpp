#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int M, N;
	vector<int> number;
	cin >> M >> N;
	for (int i = 0; i < 1000001; i++)
	{
		number.push_back(i);
	}
	
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (number[i] == 0)
			continue;
		
		for (int j = i*i; j <= N; j += i)
		{
			number[j] = 0;
		}
	}
	number[1] = 0;
	for (int i = M; i <= N; i++)
	{
		if (number[i] != 0)
		{
			cout << number[i] <<"\n";
		}
	}
	system("pause");
}