#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[501];

int n;

void solution()
{
	for (int i = n; i >= 2; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			v[i - 1][j] += max(v[i][j], v[i][j + 1]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int number;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> number;
			v[i].push_back(number);
		}
	}
	solution();
	cout << v[1][0] << "\n";
}