// 정렬, sort
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// 방 구조체 만들기
struct bang
{
	int score;
	int distance;
};

// 비교 함수 만들기
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

		// 방 정보 입력받아서 저장
		for (int i = 0; i < n; i++)
		{
			cin >> score;
			cin >> distance;
			room.push_back({ score, distance });
		}

		// 거리가 짧은 순으로 정렬
		sort(room.begin(), room.end(), cmp());

		// 제일 가까운 방의 점수를 stack에 저장
		temp.push(room[0].score);

		// stack의 상단과 다음 거리의 room의 점수를 비교, 점수가 더 높으면 stack 에 넣는다.
		for (int i = 1; i < n; i++)
		{
			if (room[i].score > temp.top())
				temp.push(room[i].score);
		}

		// stack 안의 방의 개수 출력
		cout << temp.size() << "\n";
	}
}