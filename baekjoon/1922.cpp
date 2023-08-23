// 최소 신장 트리
// 크루스칼 알고리즘
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int>>> v;
int U[1001];

int find_function(int num)
{
	if (U[num] == num)return num;
	else return U[num] = find_function(U[num]);
}

void union_function(int num1, int num2)
{
	int aRoot = find_function(num1);
	int bRoot = find_function(num2);
	U[aRoot] = bRoot;
}

void solve()
{
	for (int i = 0; i <= 1000; i++)
	{
		U[i] = i;
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		v.push_back({ weight,{start,end} });
	}

	sort(v.begin(), v.end());
	int answer = 0;

	for (int i = 0; i<v.size(); i++)
	{
		if (find_function(v[i].second.first) != find_function(v[i].second.second))
		{
			answer += v[i].first;
			union_function(v[i].second.first, v[i].second.second);
		}
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}