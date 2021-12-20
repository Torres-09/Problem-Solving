#include<iostream>

using namespace std;
unsigned int arr[31][31] = { 1 };


void solve()
{
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i < 31; i++)
	{
		arr[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
		}
		arr[i][i] = 1;
	}
}

int main()
{
	solve();
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		cout << arr[M][N] << "\n";
	}
	system("pause");
}