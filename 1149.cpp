#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1000];
vector<int> dp[1000];

void solution(int index,int size)
{
	
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, g, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r >> g >> b;
		v[i].push_back(r);
		v[i].push_back(g);
		v[i].push_back(b);
	}
}