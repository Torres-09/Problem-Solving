#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
bool *col;
int map[15] = {0};



int result = 0;

bool help(int row, int index)	//대각선에 겹치는 게 있는 지 확인하는 함수
{
	for (int i = row; i >= 0; i--)
	{
		if (i == row)
			continue;
		if (row + index == i + map[i])
			return true;
		if (row-index==i-map[i])
			return true;
	}
	return false;
}

void solve(int row)
{
	if (row == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (col[i]) continue;
		if (help(row, i)) continue;

		col[i] = true;
		map[row] = i;
		solve(row + 1);
		col[i] = false;
		map[row] = -1;
	}
}


int main()
{
	
	cin >> N;
	col = new bool[N];
	solve(0);

	cout << result << "\n";
	system("pause");
}