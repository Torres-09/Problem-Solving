#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int t;
	cin >> t;
	stack<int> arr;

	while (t--)
	{
		int number;
		cin >> number;

		if (number == 0)
		{
			arr.pop();
		}
		else
		{
			arr.push(number);
		}
		
	}

	int sum =0;

	if (arr.empty())
	{
		cout << "0\n";
		return 0;
	}

	while (!arr.empty())
	{
		sum += arr.top();
		arr.pop();
	}

	cout << sum << "\n";
}