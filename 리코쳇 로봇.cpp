#include<bits/stdc++.h>

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char arr[101][101];
bool vis[101][101];
queue<pair<pair<int,int>,int>> q;

int solution(vector<string> board) {
    
    int answer = -1;
    for(int i =0;i<board.size();i++){
        for(int j =0;j<board[i].length();j++){
            arr[i][j] = board[i][j];
            if(arr[i][j] == 'R'){
                q.push({{i,j},0});
                vis[i][j] = 1;
            } 
        }
    }
    
    while(!q.empty()){
        auto cur = q.front();
        for(int i =0;i<4;i++){
            int next_x = cur.first.first;
            int next_y = cur.first.second;
            while(1){
                next_x += dx[i];
                next_y += dy[i];
                if(next_x < 0 | next_x >= board.size() | next_y < 0 | next_y >= board[0].length() | arr[next_x][next_y] == 'D'){
                    next_x -= dx[i];
                    next_y -= dy[i];
                    break;
                }
            }
                   
            if(arr[next_x][next_y] == 'G'){
                return cur.second + 1;
            }
            if(vis[next_x][next_y]) continue;
            vis[next_x][next_y] = 1;
            
            q.push({{next_x,next_y},cur.second+1});
        }
        q.pop();
    }
    return answer;
}
