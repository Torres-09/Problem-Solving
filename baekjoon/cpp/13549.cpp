// ¼û¹Ù²ÀÁú 3
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
bool visit[100001];
int graph[100001];
queue<int> q;
int n, k;

void BFS()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int next_x;
			if (i == 0)
			{
				next_x = cur - 1;
			}
			else if (i == 1)
			{
				next_x = cur + 1;
			}
			else
			{
				next_x = 2 * cur;
			}

			if (0 <= next_x && next_x <= 100000)
			{
				if (visit[next_x] == false || graph[next_x] >= graph[cur] + 1)
				{
					if (i != 2)
					{
						q.push(next_x);
						graph[next_x] = graph[cur] + 1;
						visit[next_x] = true;
					}
				}
			}

			if (0 <= next_x && next_x <= 100000)
			{
				if (visit[next_x] == false || graph[next_x] >= graph[cur] + 1)
				{
					if (i == 2)
					{
						q.push(next_x);
						graph[next_x] = graph[cur];
						visit[next_x] = true;
					}
				}
			}
		}
	}


}

int main()
{
	memset(graph, -1, sizeof(int) * 100001);
	memset(visit, false, sizeof(bool) * 100001);

	cin >> n >> k;
	if (n == k)
	{
		cout << 0;
		return 0;
	}
	graph[n] = 0; visit[n] = true;

	q.push(n);
	BFS();

	cout << graph[k];
}