// DFS
#include<iostream>
#include<vector>

using namespace std;

vector<int> gra[101];
int visit[101];

void DFS(int vertex)
{
	visit[vertex] = 1;
	int child_vertex;

	for (int i = 0; i < gra[vertex].size(); i++)
	{
		child_vertex = gra[vertex][i];

		if (visit[child_vertex] == 0)
			DFS(child_vertex);
	}
}


int main()
{
	int t, n, m, a, b, answer;

	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		for (int i = 0; i < 101; i++)
		{
			gra[i].clear();
		}

		// 간선 추가 ( m개의 간선 )
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			gra[a].push_back(b);
		}

		// n개의 vertex에 대해서
		for (int i = 1; i <= n; i++)
		{
			// visit 초기화
			for (int j = 0; j < 101; j++)
			{
				visit[j] = 0;
			}
			
			DFS(i);
			answer = 0;

			for (int j = 0; j < 101; j++)
			{
				answer += visit[j];
			}

			cout << answer - 1 << " ";
		}
		cout << "\n";
	}
}

