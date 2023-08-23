#include<bits/stdc++.h>
using namespace std;

int main()
{
	list<int> l;
	stack<int> s;
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s.push(num);
	}

	while (!s.empty())
	{
		int si = s.top();

		if (l.empty())
			l.push_back(n--);
		else
		{
			auto i = l.begin();

			for (int j = 0; j < si; j++)
				i++;

			l.insert(i, n--);
		}
		s.pop();
	}

	for (auto i = l.begin(); i != l.end(); i++)
	{
		cout << *i << " ";
	}
}

