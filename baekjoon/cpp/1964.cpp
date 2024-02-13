#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	const int num = 45678;

	long long int result = 5;
	long long int  temp = 7;
	for (int i = 1; i < n; i++)
	{
		result += temp;
		temp += 3;
	}

	cout << result % num;
}

// 5, 5+7, 5+7+10, 5+7+10+13, 5+7+10+13+16, 