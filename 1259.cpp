#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	
	while (true)
	{
		deque<char> d;
		cin >> s;
		if (s == "0")
		{
			break;
		}

		for (int i = 0; i < s.length(); i++)
		{
			d.push_back(s[i]);
		}

		while (!d.empty())
		{
			if (d.front() == d.back())
			{
				d.pop_front();

				if (d.empty())
				{
					cout << "yes\n";
					break;
				}

				d.pop_back();

				if (d.empty())
				{
					cout << "yes\n";
				}
			}
			else
			{
				cout << "no\n";
				break;
			}
		}
	}
}