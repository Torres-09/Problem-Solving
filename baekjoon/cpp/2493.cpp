#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		s.push(number);
	}

	stack<int> sss;
	while (!s.empty())
	{
		stack<int> ss;
		ss = s;
		int last = ss.top();
		int ans = s.size()- 1;
		ss.pop();

		while (!ss.empty())
		{
			if (ss.top() > last)
			{
				break;
			}

			ss.pop();
			ans--;
		}

		s.pop();
		sss.push(ans);
	}

	while (!sss.empty())
	{
		cout << sss.top() << " ";
		sss.pop();
	}
}