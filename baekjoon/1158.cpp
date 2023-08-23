#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> q;
queue<int> answer;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    int i = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
        cnt++;
        if (cnt == k)
        {
            answer.push(q.front());
            q.pop();
            cnt = 0;
            continue;
        }
        q.push(q.front());
        q.pop();
    }

    if (answer.size() == 1)
    {
        cout << "<" << answer.front() << ">";
        return 0;
    }
    else
    {
        cout << "<";
        while (answer.size() != 1)
        {
            cout << answer.front() << ", ";
            answer.pop();
        }
        cout << answer.front();
        cout << ">";
    }
}