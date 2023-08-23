#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[301][301];
int n, m;
int answer = 0;
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isSelected[301][301];
bool isVisit[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
                q.push({i, j});
        }
    }

    // 1. 빙산이 녹는다
    // 2. BFS를 실시한다.
    // 3. 큐에 있는 빙산 중 방문되지 않은 것이 있다면 2개 이상으로 나누어진 것이다. 답을 출력한다.
    // 4. 큐에 있는 모든 것을 방문했다면 아직 빙산은 2개 이상으로 나누어 지지 않았다. 1번부터 다시 실시한다.
    while (true)
    {
        answer++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                isSelected[i][j] = 0;
                isVisit[i][j] = 0;
            }
        }

        // 빙산이 녹는다.
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            // 이미 방문했던 곳이라면 멈춘다.
            if (isSelected[x][y])
                break;
            q.pop();
            isSelected[x][y] = 1;
            int temp = 0;

            // 주변의 바닷물이 몇 곳인지 체크한다.
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // 맵을 벗어나면
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                // 빙산이 있었던 자리라면
                if (isSelected[nx][ny])
                    continue;
                // 빙산이 없는 자리가 맞으면
                if (graph[nx][ny] <= 0)
                    temp++;
            }

            graph[x][y] -= temp;
            // 아직 빙산이 남아있으면
            if (graph[x][y] > 0)
                q.push({x, y});
        }

        if(q.empty()){
            cout << 0;
            return 0;
        }

        // BFS를 실시한다.
        if (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            queue<pair<int, int>> bfsQ;
            bfsQ.push({x, y});
            isVisit[x][y] = 1;

            while (!bfsQ.empty())
            {
                int curX = bfsQ.front().first;
                int curY = bfsQ.front().second;
                bfsQ.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = curX + dx[i];
                    int ny = curY + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (isVisit[nx][ny])
                        continue;
                    if (graph[nx][ny] <= 0)
                        continue;

                    isVisit[nx][ny] = 1;
                    bfsQ.push({nx, ny});
                }
            }
        }

        // BFS 이후에 빙산들 중에 방문하지 않은 곳이 있다면 2개로 쪼개진것이다.
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.push({x, y});
            q.pop();
            if (!isVisit[x][y])
            {
                cout << answer;
                return 0;
            }
        }
    }
}