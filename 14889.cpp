// 스타트와 링크 - dfs
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int map[22][22];
bool check[22];
int result = INT_MAX;
// false - > start, true -> link

void DFS(int count, int number)
{
	if (count == n / 2)
	{
		int start = 0, link = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[i] == true && check[j] == true)
					link += map[i][j];

				if (check[i] == false && check[j] == false)
					start += map[i][j];
			}
		}

		int temp = abs(start - link);
		result = min(temp, result);
	}

	for (int i = number; i < n; i++)
	{
		check[i] = true;
		DFS(count + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	DFS(0, 1);

	cout << result << "\n";
}