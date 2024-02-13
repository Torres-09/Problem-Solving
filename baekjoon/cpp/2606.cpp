// 2606 바이러스 문제
#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[101];
bool visit[101];
int n, m;

void DFS(int start)
{
	visit[start] = true;
	

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visit[graph[start][i]] == false)
			DFS(graph[start][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int start, end;
	while (m--)
	{
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	int count = 0;
	DFS(1);
	for (int i = 0; i < 101; i++)
	{
		if (visit[i] == true)
			count++;
	}
	cout << count - 1 << "\n";
}