// ����, sort
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// �� ����ü �����
struct bang
{
	int score;
	int distance;
};

// �� �Լ� �����
struct cmp
{
	bool operator()(bang &b1, bang &b2)
	{
		return b1.distance < b2.distance;
	}
};

int main()
{
	

	int t;
	cin >> t;

	int score;
	int distance;

	while (t--)
	{
		vector<bang> room;
		stack<int> temp;

		int n;
		cin >> n;

		// �� ���� �Է¹޾Ƽ� ����
		for (int i = 0; i < n; i++)
		{
			cin >> score;
			cin >> distance;
			room.push_back({ score, distance });
		}

		// �Ÿ��� ª�� ������ ����
		sort(room.begin(), room.end(), cmp());

		// ���� ����� ���� ������ stack�� ����
		temp.push(room[0].score);

		// stack�� ��ܰ� ���� �Ÿ��� room�� ������ ��, ������ �� ������ stack �� �ִ´�.
		for (int i = 1; i < n; i++)
		{
			if (room[i].score > temp.top())
				temp.push(room[i].score);
		}

		// stack ���� ���� ���� ���
		cout << temp.size() << "\n";
	}
}