#include<iostream>
#include<cmath>

using namespace std;

void solve(int N,int num1,int num2,int num3)
{
	if (N == 1)
	{
		cout << num1 << " " << num3 << "\n";
	}
	else
	{
		solve(N - 1, num1, num3, num2);
		cout << num1 << " " << num3 << "\n";
		solve(N - 1, num2, num1, num3);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;
	cin >> N;
	int result = pow(2, N) - 1;
	cout << result << "\n";
	solve(N, 1, 2, 3);
	system("pause");
}