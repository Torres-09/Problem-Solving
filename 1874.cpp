#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> ori;
	stack<int> sta;
	bool *check = new bool[n+1];
	check[0] = true;

	
	for (int i = n; i > 0; i--)
	{
		check[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		ori.push(i);
	}

	int number;
	for (int i = 1; i <= n; i++)
	{
		cin >> number;
		
	}

}