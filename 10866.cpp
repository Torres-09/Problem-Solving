#include<iostream>
#include<string>
#include<deque>
using namespace std;
const int MAX_QUEUE_SIZE = 10000;

int main()
{
	int n;
	cin >> n;
	string cmd;
	deque<int> dq;
	int number;
	while (n--)
	{
		cin >> cmd;
		if (cmd == "push_back")
		{
			cin >> number;
			dq.push_back(number);
		}
		else if (cmd == "push_front")
		{
			cin >> number;
			dq.push_front(number);
		}
		else if (cmd == "back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
		}
		else if (cmd == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (cmd == "front")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
			dq.pop_back();
		}
	}
}