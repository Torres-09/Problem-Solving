// 스도쿠
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
using namespace std;
int map[9][9];
bool check_row[10][10];
bool check_col[10][10];
bool check_box[10][10];
list<pair<int, int>> l;
stack<pair<int, int>> s;	// 해결해야 하는 좌표

void solve()
{
	if (l.empty())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		exit(0);
	}

	pair<int, int> point = l.front();
	l.pop_front();

	for (int i = 1; i <= 9; i++)
	{
		if (check_row[point.first][i] == false && check_col[point.second][i] == false &&
			check_box[(point.first / 3) * 3 + point.second / 3][i] == false)
		{
			map[point.first][point.second] = i;
			check_row[point.first][i] = true;
			check_col[point.second][i] = true;
			check_box[(point.first / 3) * 3 + point.second / 3][i] = true;

			solve();

			map[point.first][point.second] = 0;
			check_row[point.first][i] = false;
			check_col[point.second][i] = false;
			check_box[(point.first / 3) * 3 + point.second / 3][i] = false;
		}
	}

	l.push_front({ point.first,point.second });
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 0)
				l.push_back({ i,j });
			else
			{
				check_row[i][map[i][j]] = true;	// 가로
				check_col[j][map[i][j]] = true;	// 세로
				check_box[(i / 3) * 3 + j / 3][map[i][j]] = true;
			}
		}
	}

	solve();

}