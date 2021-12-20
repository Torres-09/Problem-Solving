#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int number[10001] = { 0 };
	int N;
	cin >> N;
	while (N--)
	{
		int num;
		scanf("%d", &num);
		number[num]++;
	}
	for (int i = 1; i <= 10000;)
	{
		if (number[i] != 0)
		{
			printf("%d\n", i);
			number[i]--;
		}
		else if (number[i] == 0)
		{
			i++;
		}
	}
}