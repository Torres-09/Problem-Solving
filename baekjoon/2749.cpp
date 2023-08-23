// 행렬 연산으로 구현했음
// 분할 정복으로도 해봐야함
#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000;
typedef vector<vector<long long>> matrix;
long long n;

matrix operator * (matrix& a, matrix& b)
{
	matrix c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}

	return c;
}

void solve()
{
	cin >> n;

	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1},{1,0} };

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = ans * a;

		a = a * a;
		n /= 2;
	}

	cout << ans[0][1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}