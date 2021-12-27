#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int *number = new int[m];

	for (int i = 0; i < m; i++)
	{
		cin >> number[i];
	}

	deque<int> dq;

	// 1 ~ n
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	int count = 0;

	int i = 0;
	while (m!=0)
	{
		auto iter = find(dq.begin(), dq.end(), number[i]);
		int index = iter - dq.begin();
		if (index + 1 <= dq.size() - index)
		{
			while (dq.front() != number[i])
			{
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}
		else
		{
			while (dq.front() != number[i])
			{
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
		m--;
		i++;
	}
	cout << count << "\n";
}