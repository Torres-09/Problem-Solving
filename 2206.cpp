// 벽 부수고 이동하기
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int graph[1001][1001];
int n, m;

int main()
{
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			graph[i][j] = c - '0';
		}
	}
}