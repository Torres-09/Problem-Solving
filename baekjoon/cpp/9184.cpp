#include<iostream>
using namespace std;

int vw[105][105][105];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		if (vw[70][70][70] == 0)
		{
			vw[70][70][70] = w(20, 20, 20);
			return vw[70][70][70];
		}
		else
			return vw[70][70][70];
	}
	else
	{
		if (vw[a + 49][b + 50][c + 50] == 0)
		{
			vw[a + 49][b + 50][c + 50] = w(a - 1, b, c);
		}
		if (vw[a + 49][b + 49][c + 50] == 0)
		{
			vw[a + 49][b + 49][c + 50] = w(a - 1, b - 1, c);
		}
		if (vw[a + 49][b + 50][c + 49] == 0)
		{
			vw[a + 49][b + 50][c + 49] = w(a - 1, b, c - 1);
		}
		if (vw[a + 49][b + 49][c + 49] == 0)
		{
			vw[a + 49][b + 49][c + 49] = w(a - 1, b - 1, c - 1);
		}

		return vw[a + 49][b + 50][c + 50] + vw[a + 49][b + 49][c + 50] + vw[a + 49][b + 50][c + 49] - vw[a + 49][b + 49][c + 49];
	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				vw[i][j][k] = 0;
			}
		}
	}
	int a, b, c;
	cin >> a >> b >> c;


	while (!(a == -1 && b == -1 && c == -1))
	{
		cout << "w("<<a << ", " << b << ", " << c << ") = " <<w(a, b, c) << "\n";
		cin >> a >> b >> c;
	}
}