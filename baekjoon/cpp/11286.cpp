// Àý´ñ°ª Èü
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int n;

struct dataa
{
	int number;
	int abs_number;
};

struct cmp
{
	bool operator()(dataa &d1, dataa &d2)
	{
		if (d1.abs_number != d2.abs_number)
			return d1.abs_number > d2.abs_number;
		return d1.number > d2.number;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<dataa, vector<dataa>, cmp> pq;
	dataa data1;

	cin >> n;
	int x;
	int number;
	while (n--)
	{
		cin >> x;
		if (x != 0)
		{
			data1.number = x;
			data1.abs_number = abs(x);
			pq.push(data1);
		}
		else if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";
				continue;
			}
			else
			{
				cout << pq.top().number << "\n";
				pq.pop();
			}
		}
	}
}