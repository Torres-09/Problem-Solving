#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int graph[21][21];
int answer;
// ��, ��, ��, �� ( �ð���� )
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

	// �ʱ� ��ġ, �ʱ� ����
	pair<int, int> now = { 0,0 };
	int dir = 1;

	while (k--) {
		// ������ �������� �̵�
		int nx = now.first + dx[dir];
		int ny = now.second + dy[dir];


		// 1 �̵����⿡ ĭ�� ���ٸ� �̵� ������ �ݴ�� �� ���� �� ĭ ��������.
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			k++;
			if (dir == 1) dir = 3;
			else if (dir == 2) dir = 0;
			else if (dir == 3) dir = 1;
			else if(dir==0) dir = 2;
			continue;
		}
		else {
			// �ֻ����� ������.
			int temp;
			// 1. ����
			if (dir == 1) {
				temp = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = dice[3][1];
				dice[3][1] = temp;
			}
			// 2. ����
			else if (dir == 3) {
				temp = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = dice[3][1];
				dice[3][1] = temp;
			}
			// 3. ����
			else if (dir == 0) {
				temp = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = dice[3][1];
				dice[3][1] = temp;
			}
			// 4. ����
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

			// �̵��� �������� �������
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