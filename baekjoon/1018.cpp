#include<iostream>
#include<algorithm>

using namespace std;
char chess[50][50] = {' '};

int solve(int row, int col)
{
	int result = 0;
	if (chess[row + 7][col] == ' ' || chess[row][col + 7] == ' ')
		return 0;

	if (chess[row][col] == 'B')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((row + col + i + j) % 2 == (row + col) % 2)
				{
					if (chess[row + i][col + j] != 'B')
						result++;
				}
				else {
					if (chess[row + i][col + j] != 'W')
						result++;
				}
			}
		}
	}
	else if(chess[row][col] == 'W')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((row + col + i + j) % 2 == (row + col) % 2)
				{
					if (chess[row + i][col + j] != 'W')
						result++;
				}
				else {
					if (chess[row + i][col + j] != 'B')
						result++;
				}
			}

		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char WB;
			cin >> WB;
			chess[i][j] = WB;
		}
	}
	
	int result = 100000000;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result = min(result,solve(i, j));
		}
	}

	cout << result << "\n";
	

	system("pause");
}