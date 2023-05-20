#include<bits/stdc++.h>
using namespace std;
int n, m;
int graph[51][51];
int r, c, d;
bool Visit[51][51];
int answer;

// 북동남서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;

	// 초기위치, 방향
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	while (1) {

		// 1. 현재칸이 청소되지 않은 경우
		if (!Visit[r][c]) {
			Visit[r][c] = 1;
			answer++;
		}

		// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸 없는 경우
		int temp = 4;
		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];

			// 다음 칸이 범위를 벗어난 경우 -> 청소 할 수 없음
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				temp--;
				continue;
			}
			// 다음 칸이 벽인 경우 -> 청소 할 수 없음
			if (graph[nx][ny] == 1) {
				temp--;
				continue;
			}
			// 다음 칸이 이미 청소된 경우 -> 청소 할 수 없음
			if (Visit[nx][ny]) {
				temp--;
				continue;
			}
		}

		if (temp == 0) {
			int nx = r + dx[(d + 2) % 4];
			int ny = c + dy[(d + 2) % 4];
			// 바라보는 방향의 뒤쪽이 벽이라면 작동중지한다.
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
			if (graph[nx][ny] == 1) break;

			// 바라보는 방향을 유지하고, 한 칸 후진하고 1번으로 돌아간다.
			r = nx;
			c = ny;
			continue;
		}
		// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		else {
			// 반 시계 방향 90 회전
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (graph[nx][ny] == 1) continue;
			if (!Visit[nx][ny]) {
				r = nx;
				c = ny;
			}
		}

	}

	cout << answer;
}
