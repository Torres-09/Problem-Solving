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

	// case 3��, ������ �� �� x�࿡ ������ ���, ������ �� �� y �࿡ �����ϴ� ���, ���� x�� y�࿡ �����ϴ� ���
	//case 1
	if (p1.y == p2.y&&p3.y == p4.y)		// �� �� x��ǥ�� ����
	{
		if (p1.x > p3.x)
		{
			swap(p1, p3);
			swap(p2, p4);
		}
		//l1,l2 ��ġ ����

		if (p1.y != p3.y)			// y��ǥ�� �ٸ���� -> ���� ������ �ʴ´�.
			cout << "1\n";
		else if (p3.x > p2.x)		// y��ǥ�� ������ ������ �ʴ°��
			cout << "1\n";
		else if (p2.x == p3.x)	// �� ������ ������ ���
			cout << "2\n";
		else if (p2.x > p3.x&&p4.x > p2.x && !(p1.x == p3.x))	// �Ϻΰ� ������ ���
			cout << "3\n";
		else if (p3.x < p2.x&&p2.x >= p4.x)	// �� ������ �ٸ� ���п� ���ԵǴ� ���
			cout << "4\n";
		else if (p1.x == p3.x&&p2.x == p4.x)	// �� ������ ���� ���
			cout << "4\n";
		else
			cout << "4\n";
	}

	//case 2
	else if (p1.x == p2.x&&p3.x == p4.x)		// �� ��y��ǥ�� ����
	{
		if (p1.y > p3.y)
		{
			swap(p1, p3);
			swap(p2, p4);
		}
		//l1,l2 ��ġ ����

		if (p1.x != p3.x)			// x��ǥ�� �ٸ���� -> ���� ������ �ʴ´�.
			cout << "1\n";
		else if (p3.y > p2.y)		// x��ǥ�� ������ ������ �ʴ°��
			cout << "1\n";
		else if (p2.y == p3.y)	// �� ������ ������ ���
			cout << "2\n";
		else if (p2.y > p3.y&&p4.y > p2.y && !(p1.y == p3.y))	// �Ϻΰ� ������ ���
			cout << "3\n";
		else if (p3.y < p2.y&&p2.y >= p4.y)
			cout << "4\n";
		else if (p1.y == p3.y&&p2.y == p4.y)
			cout << "4\n";
		else
			cout << "4\n";
	}

	//case3
	else //���� x�� y�࿡ �����ϴ� ���
	{
		//l1�� ���η�
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