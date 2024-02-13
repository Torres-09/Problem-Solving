// priority queue (heap)
// cmp
// max heap을 만든 후에 k개가 남을 때까지 pop, 이후에 하나 씩 넣으면서 max를 출력

#include<iostream>
#include<queue>
#include<vector>
#include<math.h>

using namespace std;

int t, m, n, k, _x, _y;

struct Point {
	int x, y;
};

double distance(int x, int y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

struct cmp
{
	bool operator()(Point &p1, Point &p2)
	{
		if (distance(p1.x, p1.y) == distance(p2.x, p2.y))
		{
			if (p1.x == p2.x)
				return p1.y < p2.y;
			else
				return p1.x < p2.x;
		}
		return distance(p1.x, p1.y) < distance(p2.x, p2.y);
	}
};

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		priority_queue<Point,vector<Point>,cmp> store;
		Point point;

		for (int i = 0; i < m; i++)
		{
			cin >> _x >> _y;
			point.x = _x;
			point.y = _y;
			store.push(point);

			if (store.size() > k)
				store.pop();
		}

		for (int i = 0; i < n; i++)
		{
			cin >> _x >> _y;
			point.x = _x;
			point.y = _y;
			store.push(point);
			store.pop();
			cout << store.top().x << " " << store.top().y << "\n";
		}
	}
}