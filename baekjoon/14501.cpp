#include <iostream>
#include <algorithm>

using namespace std;

// 걸리는 시간, 비용
pair<int, int> arr[20];
int answer;
int n;

// 날짜, 현재까지의 수임료
void solve(int day, int price){
    if(day > n + 1) return;
    answer = max(answer, price);
    if(day==n + 1) return;

    if(day + arr[day].first <= n+1) solve(day + arr[day].first, price + arr[day].second);
    if(day + 1 <= n+1) solve(day+1,price);

    // for(int i = day;i<n;i++){
    //     if(day + arr[i].first < n){
    //         solve(day + arr[i].first, price + arr[i].second);
    //     }
    // }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    solve(1,0);
    cout << answer;
}