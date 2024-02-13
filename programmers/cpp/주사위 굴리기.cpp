#include<bits/stdc++.h>
using namespace std;
int n, m;
int dice[4][3];
int x, y;
int k;
int graph[21][21];
int dir[1001];

// 동 서 북 남
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		dir[i] = num - 1;
	}

	int cnt = 0;

	// 동서북남
	while (k--) {
		int nx = x + dx[dir[cnt]];
		int ny = y + dy[dir[cnt]];
		int temp = 0;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			cnt++;
			continue;
		}

		if (dir[cnt] == 0) {
			temp = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = temp;
		}
		else if (dir[cnt] == 1) {
			temp = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = temp;
		}
		else if (dir[cnt] == 2) {
			temp = dice[0][1];
			dice[0][1] = dice[1][1];
			dice[1][1] = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = temp;
		}
		else {
			temp = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = dice[0][1];
			dice[0][1] = temp;
		}

		if (graph[nx][ny] == 0) {
			graph[nx][ny] = dice[3][1];
		}
		else {
			dice[3][1] = graph[nx][ny];
			graph[nx][ny] = 0;
		}

		cout << dice[1][1] << "\n";

		x = nx;
		y = ny;
		cnt++;
	}
}
