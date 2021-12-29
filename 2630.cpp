#include<iostream>

using namespace std;
int v[129][129];

struct paperinfo
{
	int white = 0;
	int blue = 0;
};

paperinfo solution(int x,int y, int size)
{
	paperinfo result;

	if (size == 1)
	{
		if (v[x][y] == 0)
			result.white = 1;
		else
			result.blue = 1;

		return result;
	}

	paperinfo status[4];
	status[0] = solution(x, y, size / 2);
	status[1] = solution(x+size/2, y, size / 2);
	status[2] = solution(x, y+size/2, size / 2);
	status[3] = solution(x + size / 2, y + size / 2, size / 2);

	for (int i = 0; i < 4; i++)
	{
		result.white += status[i].white;
		result.blue += status[i].blue;
	}

	if (result.blue == 0)
		result.white = 1;
	if (result.white == 0)
		result.blue = 1;

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
	cout << answer.white << "\n" << answer.blue <<"\n";
}