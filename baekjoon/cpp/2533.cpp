#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
vector<int> graph[1000001];
int dp[1000001];
int n;

int solve(int vertex){
    // 자식이 더 이상 없을 때
    if(graph[vertex].size() == 0) return 1;

    for(int i =0;i<graph[vertex].size();i++){
        dp[vertex] = max(solve(graph[vertex][i]), (int) graph[vertex].size());
    }

    return dp[vertex];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    int u,v;
    for(int i =0;i<n-1;i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }
    solve(1);
    for(int i =1;i<=n;i++) cout << dp[i] << " ";
}