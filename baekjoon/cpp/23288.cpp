#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int graph[21][21];
int answer;
// 북, 동, 남, 서 ( 시계방향 )
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dice[4][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m >> k;
	dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	// 초기 위치, 초기 방향
	pair<int, int> now = { 0,0 };
	int dir = 1;

	while (k--) {
		// 설정된 방향으로 이동
		int nx = now.first + dx[dir];
		int ny = now.second + dy[dir];


		// 1 이동방향에 칸이 없다면 이동 방향을 반대로 한 다음 한 칸 굴러간다.
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			k++;
			if (dir == 1) dir = 3;
			else if (dir == 2) dir = 0;
			else if (dir == 3) dir = 1;
			else if(dir==0) dir = 2;
			continue;
		}
		else {
			// 주사위를 굴린다.
			int temp;
			// 1. 동쪽
			if (dir == 1) {
				temp = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = dice[3][1];
				dice[3][1] = temp;
			}
			// 2. 서쪽
			else if (dir == 3) {
				temp = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = dice[3][1];
				dice[3][1] = temp;
			}
			// 3. 북쪽
			else if (dir == 0) {
				temp = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = dice[3][1];
				dice[3][1] = temp;
			}
			// 4. 남쪽
			else {
				temp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = temp;
			}

			int a = dice[3][1];
			int b = graph[nx][ny];
			int c = 0;


			if (a > b) dir = (dir + 1) % 4;
			else if (a < b) dir = (dir + 3) % 4;
			else dir = dir;

			now.first = nx;
			now.second = ny;

			// 이동을 마쳤으니 점수계산
			queue<pair<int, int>> q;
			q.push(now);
			bool Visit[21][21];
			for (int i = 0; i < 21; i++) {
				for (int j = 0; j < 21; j++) {
					Visit[i][j] = 0;
				}
			}
			while (!q.empty()) {
				
				int x = q.front().first;
				int y = q.front().second;
				Visit[x][y] = true;
				c++;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];


					if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
					if (Visit[next_x][next_y]) continue;

					if (b == graph[next_x][next_y]) {
						q.push({ next_x,next_y });
						Visit[next_x][next_y] = 1;
					}
				}
			}

			answer += b * c;
		}
	}

	cout << answer << "\n";
}