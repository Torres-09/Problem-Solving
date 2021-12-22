#include<iostream>

using namespace std;

struct Point
{
	int x, y;
	bool operator<(Point const& p) {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
	bool operator<=(Point const& p) {
		if (x == p.x) {
			return y <= p.y;
		}
		return x <= p.x;
	}
	bool operator==(Point const& p)
	{
		if (x == p.x)
		{
			return y == p.y;
		}
		return false;
	}
	bool operator!=(Point const& p)
	{
		if (x == p.x)
		{
			return y != p.y;
		}
		return x != p.x;
	}
};

void solve()
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	Point p1, p2, p3, p4;

	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	p3.x = x3;
	p3.y = y3;
	p4.x = x4;
	p4.y = y4;

	if (p2 < p1)
		swap(p1, p2);
	if (p4 < p3)
		swap(p3, p4);

	// case 3개, 선분이 둘 다 x축에 평행한 경우, 선분이 둘 다 y 축에 평행하는 경우, 각각 x축 y축에 평행하는 경우
	//case 1
	if (p1.y == p2.y&&p3.y == p4.y)		// 둘 다 x좌표에 평행
	{
		if (p1.x > p3.x)
		{
			swap(p1, p3);
			swap(p2, p4);
		}
		//l1,l2 위치 조정

		if (p1.y != p3.y)			// y좌표가 다른경우 -> 평행 만나지 않는다.
			cout << "1\n";
		else if (p3.x > p2.x)		// y좌표는 같지만 만나지 않는경우
			cout << "1\n";
		else if (p2.x == p3.x)	// 한 점에서 만나는 경우
			cout << "2\n";
		else if (p2.x > p3.x&&p4.x > p2.x && !(p1.x == p3.x))	// 일부가 만나는 경우
			cout << "3\n";
		else if (p3.x < p2.x&&p2.x >= p4.x)	// 한 선분이 다른 선분에 포함되는 경우
			cout << "4\n";
		else if (p1.x == p3.x&&p2.x == p4.x)	// 두 선분이 같은 경우
			cout << "4\n";
		else
			cout << "4\n";
	}

	//case 2
	else if (p1.x == p2.x&&p3.x == p4.x)		// 둘 다y좌표에 평행
	{
		if (p1.y > p3.y)
		{
			swap(p1, p3);
			swap(p2, p4);
		}
		//l1,l2 위치 조정

		if (p1.x != p3.x)			// x좌표가 다른경우 -> 평행 만나지 않는다.
			cout << "1\n";
		else if (p3.y > p2.y)		// x좌표는 같지만 만나지 않는경우
			cout << "1\n";
		else if (p2.y == p3.y)	// 한 점에서 만나는 경우
			cout << "2\n";
		else if (p2.y > p3.y&&p4.y > p2.y && !(p1.y == p3.y))	// 일부가 만나는 경우
			cout << "3\n";
		else if (p3.y < p2.y&&p2.y >= p4.y)
			cout << "4\n";
		else if (p1.y == p3.y&&p2.y == p4.y)
			cout << "4\n";
		else
			cout << "4\n";
	}

	//case3
	else //각각 x축 y축에 평행하는 경우
	{
		//l1을 가로로
		if (p3.y == p4.y)
		{
			swap(p1, p3);
			swap(p2, p4);
		}

		if (p1.x <= p3.x&&p2.x >= p3.x)
		{
			if (p1.y >= p3.y&&p1.y <= p4.y)
			{
				cout << "2\n";
			}
			else
				cout << "1\n";
		}
		else
			cout << "1\n";

	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}