#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[2][101][101];

	int n, m;
	cin >> n >> m;

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[k][i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[0][i][j] + a[1][i][j] << " ";
		}
		cout << "\n";
	}
}