#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> graph[100001];		// { 정점, 가중치 }
bool visit[100001];
int maxdis = 0;
int maxvertex = 1;
int n;

void dfs(int start, int dist)
{
	if (visit[start] == true)
		return;

	visit[start] = true;

	if (dist > maxdis)
	{
		maxdis = dist;
		maxvertex = start;
	}

	for (int i = 0; i < graph[start].size(); i++)
	{
		dfs(graph[start][i].first, graph[start][i].second + dist);
	}


}

int main()
{
	cin >> n;

	int a, b;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			graph[c].push_back({ a,b });
			graph[a].push_back({ c,b });
		}
	}

	dfs(1, 0);
	memset(visit, false, sizeof(visit));
	dfs(maxvertex, 0);
	cout << maxdis << "\n";
}