#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	int x;
	while (n--)
	{
		cin >> x;
		if (x > 0)
		{
			pq.push(x);
		}
		else if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}