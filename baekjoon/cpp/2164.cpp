#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	int number;
	while (q.size() != 1)
	{
		q.pop();
		number = q.front();
		q.push(number);
		q.pop();
	}

	cout << q.front() << "\n";
}