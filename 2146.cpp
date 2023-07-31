#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int n;
int arr[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool Visit[101][101];
queue<pair<int,int>> q;
// 최대 100개의 이하의 섬
vector<pair<int, int>> v[10010];
int x,y;
int next_x,next_y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 섬 0 번 째
    int index = 0;

    // 모든 점에서 확인
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 바다입니다.
            if (arr[i][j] == 0)
                continue;
            // 이미 방문했습니다.
            if (Visit[i][j])
                continue;

            // 섬이 시작됩니다.
            q = {};
            q.push({i, j});
            Visit[i][j] = 1;
            while (!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                v[index].push_back({x, y});
                

                for (int k = 0; k < 4; k++)
                {
                    next_x = x + dx[k];
                    next_y = y + dy[k];

                    // 맵을 벗어났다.
                    if (next_x < 0 | next_x >= n | next_y < 0 | next_y >= n)
                        continue;
                    // 바다이거나 이미 방문한 지역인 경우
                    if (Visit[next_x][next_y] | arr[next_x][next_y] == 0)
                        continue;
                    q.push({next_x, next_y});

                    // 방문했습니다.
                    Visit[next_x][next_y] = 1;
                }
            }

            // 섬 하나의 탐험이 끝났습니다.
            index++;
        }
    }
    // 모든 섬 탐색을 마쳤습니다.

    int result = INT_MAX;
    int x1,y1,x2,y2;
    // 모든 섬에 대해 다리건설을 찾습니다.
    for (int i = 0; i < index; i++)
    {
        for (int j = i; j < index; j++)
        {
            if (i == j)
                continue;

            // i번 째 섬, j 번 째 섬
            for (int k = 0; k < v[i].size(); k++)
            {
                for (int z = 0; z < v[j].size(); z++)
                {
                    x1 = v[i][k].first;
                    y1 = v[i][k].second;
                    x2 = v[j][z].first;
                    y2 = v[j][z].second;
                    result = min(abs(x1 - x2) + abs(y1 - y2), result);
                }
            }
        }
    }

    cout << result - 1;
}