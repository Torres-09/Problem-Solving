#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	stack<int> sta;
	int t;
	cin >> t;
	string cmd;
	while (t--)
	{
		getline(cin, cmd, '\n');
		if (cmd == "push")
		{
			int number;
			cin >> number;
			sta.push(number);
			cin.ignore();
		}
		else if (cmd == "top")
		{
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
			cout << sta.top() <<"\n";
			sta.pop();
		}
	}
}