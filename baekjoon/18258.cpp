#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	queue<int> q;
	string s;
	while (t--)
	{
		cin >> s;
		if (s == "push")
		{
			int number;
			cin >> number;
			q.push(number);
		}
		else if (s == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.front() << "\n";
		}
		else if (s == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.front() << "\n";
			q.pop();
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (s == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << q.back() << "\n";
		}
	}
}