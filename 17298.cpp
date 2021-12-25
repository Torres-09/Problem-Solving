#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	stack<int> sta;
	int* seq  = new int[n];
	int* answer = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!sta.empty())
		{
			if (sta.top() > seq[i])
			{
				answer[i] = sta.top();
				sta.push(seq[i]);
				break;
			}
			else
			{
				sta.pop();
			}
		}

		if (sta.empty())
		{
			sta.push(seq[i]);
			answer[i] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
}