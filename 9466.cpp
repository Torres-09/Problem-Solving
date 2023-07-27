#include <iostream>
#include<vector>
#include <stack>

using namespace std;
int answer;
vector<int> v;
vector<int> Visit;
stack<int> s;

void DFS(int index){
    // 혼자 팀을 결성한 곳 까지 도달함 or 이미 팀이 있이 완성되어 있음
    if(Visit[index] == 1 || Visit[index] == 3){
        return;
    }

    if(Visit[index] == -1){
        return;
    }

    // cycle 안에 들어온 경우
    if(Visit[index] == 2){
        // 해당 index가 나오는 시점까지 stack에서 팀의 크기를 찾는다.
        int Count = 0;
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            Count++;
            // 팀을 완성한 경우에는 3으로 표시
            Visit[temp] = 3;
            if(temp == index){
                answer -= Count;
                return;
            }
        }
    }

    // 팀 조직 중
    Visit[index] = 2;
    s.push(index);

    DFS(v[index]);

    // 팀 결성을 하다가 결성이 되지 못했으면, 넌 혼자 해라
    if(Visit[index] == 2) Visit[index] = -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // 학생의 수
        answer = n;

        // 초기화
        v.assign(n + 1, 0);
        Visit.assign(n+1, 0);

        // 각 학생 선호 입력
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];

            // 본인 혼자 팀을 결성하는 경우에는 바로 check
            if(v[i] == i){
                Visit[i] = 1;
                answer--;
            }
        }


        for(int i =1;i<=n;i++){
            s = stack<int>();
            if(Visit[i]==0)
                DFS(i);
        } 

        cout << answer << "\n";
    }
}