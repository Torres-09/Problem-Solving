// 이분 그래프
#include<vector>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int t,v,e;
int visit[20001];


bool BFS(int start, vector<int> graph[], queue<int> q)
{
	visit[start] = 1;
	q.push(start);

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (visit[graph[vertex][i]] == visit[vertex])
			{
				return false;
			}

			if (visit[graph[vertex][i]] == 0)
			{
				if (visit[vertex] == 1)
				{
					visit[graph[vertex][i]] = 2;
					q.push(graph[vertex][i]);
				}
				else if (visit[vertex] == 2)
				{
					visit[graph[vertex][i]] = 1;
					q.push(graph[vertex][i]);
				}
			}
		}
	}

	return true;
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(visit, 0, sizeof(int)*20001);
		vector<int> graph[20001];
		queue<int> q;

		cin >> v >> e;
		int a, b;
		for (int i = 0; i < e; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		int number = 1;
		bool check = true;

		while (1)
		{
			if (visit[number] == 0)
				if (BFS(number, graph, q) == false)
				{
					check = false;
					break;
				}

			number++;

			if (number > v)
				break;
		}

		if (check == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}