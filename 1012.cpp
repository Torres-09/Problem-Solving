//¿Ø±‚≥ÛπË√ﬂ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char vagetable[51][51];
bool visit[51][51];
int check;
int m, n, k;

void DFS(int row, int col)
{
	if (visit[row][col] == true)
		return;

	visit[row][col] = true;

	if (vagetable[row][col] == '1')
	{
		check++;

		if (col != 0)
			DFS(row, col - 1);
		if (row != 0)
			DFS(row - 1, col);
		if (col != n - 1)
			DFS(row, col + 1);
		if (row != m - 1)
			DFS(row + 1, col);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		vector<int> sum;

		for (int a = 0; a < 51; a++)
		{
			for (int b = 0; b < 51; b++)
			{
				visit[a][b] = false;
				vagetable[a][b] = '0';
			}
		}

		cin >> m >> n >> k;

		int i, j;

		for (int a = 0; a < k; a++)
		{
			cin >> i >> j;
			vagetable[i][j] = '1';
		}

		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				check = 0;
				DFS(a, b);
				if (check != 0)
					sum.push_back(check);
			}
		}

		cout << sum.size() << "\n";

	}

	
}