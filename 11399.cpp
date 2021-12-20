#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *num = new int[N];

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		num[i] = k;
	}
	sort(num, num + N);
	
	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		sum = sum + num[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		result = sum + result;
		sum = sum - num[i];
	}
	
	cout << result << "\n";
	system("pause");
}