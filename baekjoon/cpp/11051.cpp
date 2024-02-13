//이항 계수 2
#include<iostream>

using namespace std;
int arr[1001][1001] = { 1 };


void solve()
{
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	//arr[2][0] = 1
	//arr[2][1] = 2
	//arr[2][2] = 1
	//arr[3][0] = 1
	//arr[3][1] = 3
	//arr[4][2] = 6
	for (int i = 2; i < 1001; i++)
	{
		arr[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j])%10007;
		}
		arr[i][i] = 1;
	}
	
}



int main()
{
	int N, K;
	cin >> N >> K;
	solve();
	cout << arr[N][K];
	system("pause");
}