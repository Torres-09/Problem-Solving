// 절단점 알고리즘
#include<bits/stdc++.h>
using namespace std;
int v, e;
vector<int> graph[10001];
bool cutVertex[10001];
int answer[10001];
int VisitOrder[10001];
int DFS(int, int);
int Count = 0;
int order =0 ;

void solve()
{
	cin >> v >> e;

	int start, end;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i <= v; i++)
	{
		if (VisitOrder[i] == 0)
			DFS(i, 0);
	}

	for (int i = 1; i <= v; i++)
	{
		if (cutVertex[i]) answer[Count++] = i;
	}

	cout << Count << "\n";

	for (int i = 0; i < Count; i++)
		cout << answer[i] << " "; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}

int DFS(int cur, int par) {
	VisitOrder[cur] = order + 1;
	order++;

	int minOrder = VisitOrder[cur];

	int child = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];

		if (next == par) continue;


		if (VisitOrder[next] > 0)
		{
			minOrder = min(VisitOrder[next], minOrder);
		}
		else
		{
			child++;
			int low = DFS(next, cur);

			if (par!=0&&VisitOrder[cur] <= low) cutVertex[cur] = 1;

			minOrder = min(low, minOrder);
		}

	}

	if (par == 0 && child >= 2)cutVertex[cur] = 1;
	return minOrder;
}