#include<bits/stdc++.h>
using namespace std;
long long n;
long long fibo[18] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };
long long mod = 1000000007;
long long dp[100000000];
typedef vector<vector<long long>> matrix;

matrix operator * (matrix& a, matrix& b)
{
	matrix c(2, vector<long long>(2));

	for(int i =0;i<2;i++)
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= mod;
		}
	
	return c;
}

void solve()
{
	cin >> n;

	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1}, { 1,0} };

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = ans * a;

		a = a * a;
		n /= 2;
	}

	cout << ans[0][1];

}

int main()
{
	solve();
}