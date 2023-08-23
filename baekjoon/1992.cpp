#include<iostream>
using namespace std;
char v[65][65];

void solution(int x, int y, int size)
{
	if (size == 1)
	{
		cout << v[y][x];
		return;
	}

	char check = v[y][x];

	for (int j = y; j < y + size; j++)
	{
		for (int i = x; i < x + size; i++)
		{
			if (check != v[j][i])
			{
				cout << "(";
				solution(x, y, size / 2);
				solution(x+size/2, y, size / 2);
				solution(x, y + size / 2, size / 2);
				solution(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << check;
	return;
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

	solution(0, 0, n);
	
}