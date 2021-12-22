// 오델로
// 나오면 그냥 틀려
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int grid[21][21];
struct point_info {
	int x, y;
};

set<point_info> candidate;
set<point_info>::iterator iter;
vector<int>check[20][20][2];

int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,1,-1,0,1,-1 };
int n, q, t;
void aroundcandidate(int n1, int n2);
int candidatecheck();

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> q;
		grid[n / 2][n / 2] = grid[n/2 + 1][n/2 + 1] = 1;
		grid[n / 2 + 1][n / 2] = grid[n / 2][n / 2 + 1] = 2;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				aroundcandidate(n / 2 + i, n / 2 + j);
			}
		}

		int turn = 1;
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			int flag = candidatecheck();

			if ((flag &&  turn) == 0)
				turn = flag;

			if (grid[x][y] != 0)
				continue;
			if (check[x][y][turn].empty() == true)
				continue;

			for (int k = 0; check[x][y][turn].size(); k++)
			{
				int i = check[x][y][turn][k];
				for (int j = 0; j < n; j++)
				{
					if (grid[x + dx[i] * j][y + dy[i] * j] == turn)
						break;
					grid[x + dx[i] * j][y + dy[i] * j] = turn;
				}
				grid[x][y] = turn;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
				candidate.erase(point_info({ x , y }));
				aroundcandidate(x, y);
			}
		}

		int anscheck = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					anscheck += 1;
				else if (grid[i][j] == 2)
					anscheck -= 1;
			}
		}

		if (anscheck > 0)
			cout << 2 << "\n";
		else if (anscheck < 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
}

int candidatecheck()
{
	int result = 0;
	for (iter = candidate.begin(); iter != candidate.end(); iter++)
	{
		check[iter->x][iter->y][0].clear();
		check[iter->x][iter->y][1].clear();

		for (int i = 0; i < 8; i++)
		{
			int flag = grid[iter->x + dx[i]][iter->y + dy[i]];
			if (flag <= 0)
				continue;
			for (int j = 1; j < n; j++)
			{
				if (grid[iter->x + dx[i] * j][iter->y + dy[i] * j] <= 0)
					break;
				else if (grid[iter->x + dx[i] * j][iter->y + dy[i] * j] != flag)
				{
					check[iter->x][iter->y][grid[iter->x + dx[i] * j][iter->y + dy[i] * j]].push_back(i);
					result |= grid[iter->x + dx[i] * j][iter->y + dy[i] * j];
					break;
				}
			}
		}
	}
	return result;
}

void aroundcandidate(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int X = x + dx[i];
		int Y = y + dy[i];
		if (grid[X][Y] == 0)
			candidate.insert(point_info({ X,Y }));
	}

}