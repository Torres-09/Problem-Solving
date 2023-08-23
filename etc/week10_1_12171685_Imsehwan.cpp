// BFS 그래프 순회 사용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int T, A, B;
vector <int> road[10000];
int check[10000];
queue<int> q;

void init() {
	for (int i = 0; i < 10000; i++) {
		check[i] = 10000;
	}
}

int main() 
{
	// 각 방에서 갈 수 있는 방 구하기
	for (int i = 0; i < 10000; i++)
	{
		//뒤로 한 칸
		if (i != 0)
			road[i].push_back(i - 1);

		//앞으로 한 칸
		if (i != 9999)
			road[i].push_back(i + 1);

		// 역수 구하기
		int num = 0, temp = i;

		for (int j = 0; j < 4; j++) {
			num = (num * 10) + (temp % 10);
			temp = temp / 10;
		}

		road[i].push_back(num);

	}

	cin >> T;

	// BFS
	while (T--) {
		init();
		cin >> A >> B;
		check[A] = 0;
		q.push(A);
		while (!q.empty()) 
		{
			int now = q.front();
			q.pop();

			for (int i = 0; i < road[now].size(); i++) 
			{
				if (check[road[now][i]] > check[now] + 1) 
				{
					q.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}

		cout << check[B] << "\n";
	}

	return 0;
}