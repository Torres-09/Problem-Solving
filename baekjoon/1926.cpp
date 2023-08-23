#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int board[501][501];
bool vis[501][501];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int Count = 0;
int max_size = 0;
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && vis[i][j] == false)
            {
                int size = 0;
                q.push({i, j});
                vis[i][j] = 1;
                size++;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if (vis[nx][ny] == false && board[nx][ny] == 1 && nx >= 0 && nx < n && ny >= 0 && ny < m)
                        {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                            size++;
                        }
                    }
                }
                max_size = max(max_size, size);
                Count++;
            }
        }
    }

    cout << Count << "\n"
         << max_size;
}