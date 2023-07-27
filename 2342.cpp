#include <iostream>
#include <cmath>
#include <climits>
#include<vector>

using namespace std;
long dp[100002][5][5];
vector<int> arr;
long Move[5][5];

long solve(int cnt, int Left, int Right)
{
    if (cnt == arr.size() -1)
        return 0;

    // 왼오는 같이 있을 수 없다. (0,0)이 아닌 순간에
    if(Left == Right && Left != 0 && Right != 0) return INT_MAX;
    if(dp[cnt][Left][Right] != 0) return dp[cnt][Left][Right];

    // dp[0][0][0] = min(solve(1, 0, 1) + Move(0, 1),solve(1,1,0) + Move(0,1));
    return dp[cnt][Left][Right] = min(solve(cnt + 1, Left, arr[cnt + 1]) + Move[Right][arr[cnt+1]],
                                      solve(cnt + 1, arr[cnt + 1], Right) + Move[Left][arr[cnt+1]]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int num;
    arr.push_back(0);

    // 같은 버튼 누르기
    for(int i =1;i<=4;i++) Move[i][i] = 1;

    // 중앙에서 움직임
    for(int i=1;i<5;i++){
        Move[0][i] = 2;
        Move[i][0] = 2;
    }

    // 반대편으로 이동
    Move[1][3] = 4;
    Move[3][1] = 4;
    Move[2][4] = 4;
    Move[4][2] = 4;

    // 근처로 이동
    Move[1][2] = 3;
    Move[1][4] = 3;
    Move[2][1] = 3;
    Move[2][3] = 3;
    Move[3][2] = 3;
    Move[3][4] = 3;
    Move[4][1] = 3;
    Move[4][3] = 3;

    // 입력
    while (1)
    {
        cin >> num;
        arr.push_back(num);
        if (arr.back() == 0)
        {
            arr.pop_back();
            break;
        }
    }

    solve(0, 0, 0);
    cout << dp[0][0][0];
}