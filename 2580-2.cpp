// 스도쿠
#include<iostream>
#include<queue>
using namespace std;
int map[10][10];
bool check_row[10][10];
bool check_col[10][10];
bool check_box[10][10];
queue<pair<int, int>> q; // 해결해야 할 좌표

void solve()
{
	while (!q.empty())
	{
		bool result = false;
		pair<int, int> point = q.front();

		for (int i = 1; i <= 9; i++)
		{
			if (check_row[point.first][i] == false && check_col[point.second][i] == false &&
				check_box[(point.first / 3) * 3 + point.second / 3][i] == false)
			{
				map[point.first][point.second] = i;
				check_row[point.first][i] = true;
				check_col[point.second][i] = true;
				check_box[(point.first / 3) * 3 + point.second / 3][i] = true;
				result = true;
				break;
			}
		}

		if (result == true)
		{
			q.pop();
		}
		else
		{
			q.pop();
			q.push(point);
		}
	}
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
			{
				q.push({ i,j });
			}
			else
			{
				check_row[i][map[i][j]] = true;	// 가로
				check_col[j][map[i][j]] = true;	// 세로
				check_box[(i / 3) * 3 + j / 3][map[i][j]] = true;	//박스
			}
		}
	}

	solve();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}