#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		char c;
		stack<char> sta;

		while (true)
		{
			cin >> c;

			if (c == '\n')
				break;
			else
				sta.push(c);
		}

		int check = 0;
		while (!sta.empty())
		{
			if (sta.top() == '(')
			{
				check++;
				sta.pop();
			}
			else
			{
				check--;
				sta.pop();
			}
		}

		if (check == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}