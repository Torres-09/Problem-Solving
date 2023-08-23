// 회의실 배정
#include<iostream>
#include<queue>
using namespace std;
int n;

struct cmp {
	bool operator()(pair<int, int>&a, pair<int, int>&b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main()
{
	cin >> n;
	int start, end;
	priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> meet;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		meet.push({ start,end });
	}

	int result = 0;
	int temp;
	
	while (1)
	{
		temp = meet.top().second;
		meet.pop();
		result++;

		while ((!meet.empty()) && meet.top().first < temp)
			meet.pop();

		if (meet.empty())
			break;
	}

	cout << result << "\n";
}