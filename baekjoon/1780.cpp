#include<iostream>
using namespace std;
int v[2188][2188];

struct paperinfo
{
	int minus = 0;
	int zero = 0;
	int one = 0;
};

paperinfo solution(int x, int y, int size)
{
	paperinfo result;
	if (size == 1)
	{
		if (v[x][y] == -1)
		{
			result.minus = 1;
		}
		else if (v[x][y] == 0)
		{
			result.zero = 1;
		}
		else
			result.one = 1;

		return result;
	}

	paperinfo status[9];
	status[0] = solution(x, y, size / 3);
	status[1] = solution(x + size / 3, y, size / 3);
	status[2] = solution(x + size / 3 + size / 3, y, size / 3);
	status[3] = solution(x, y + size / 3, size / 3);
	status[4] = solution(x + size / 3, y + size / 3, size / 3);
	status[5] = solution(x + size / 3 + size / 3, y + size / 3, size / 3);
	status[6] = solution(x, y + size / 3 + size / 3, size / 3);
	status[7] = solution(x + size / 3, y + size / 3 + size / 3, size / 3);
	status[8] = solution(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3);

	for (int i = 0; i < 9; i++)
	{
		result.minus += status[i].minus;
		result.zero += status[i].zero;
		result.one += status[i].one;
	}

	if (result.minus == 0 && result.zero == 0)
		result.one = 1;
	else if (result.minus == 0 && result.one == 0)
		result.zero = 1;
	else if (result.zero == 0 && result.one == 0)
		result.minus = 1;

	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	paperinfo answer = solution(0, 0, n);
	cout << answer.minus << "\n" << answer.zero << "\n" << answer.one << "\n";
}