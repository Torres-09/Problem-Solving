#include<iostream>
#include<queue>
using namespace std;

struct info
{
	int num, index;
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		queue<info> q;
		priority_queue<int> pq;
		int answer = 1;

		int num;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			q.push({num,i});
			pq.push(num);
		}


		int count = 0;
		while (q.size() != 1)
		{
			if (q.front().num < pq.top())
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				if (q.front().index == m)
				{
					q.pop();
					pq.pop();
					count++;
					answer = count;
				}
				else
				{
					q.pop();
					pq.pop();
					count++;
				}

			}
		}

		if (q.front().index == m)
			cout << count + 1 << "\n";
		else
			cout << answer << "\n";

		answer = 1;
	}
}