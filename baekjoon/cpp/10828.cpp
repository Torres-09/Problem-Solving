#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	stack<int> sta;
	int t;
	cin >> t;
	string cmd;
	while (t--)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			int number;
			cin >> number;
			sta.push(number);
		}
		else if (cmd == "top")
		{
			if (sta.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << sta.top() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << sta.empty() << "\n";
		}
		else if (cmd == "size")
		{
			cout << sta.size() << "\n";
		}
		else if (cmd == "pop")
		{
			if (sta.empty())
			{
				cout << "-1\n";
			}
			else {
				cout << sta.top() << "\n";
				sta.pop();
			}
			
		}
	}
}