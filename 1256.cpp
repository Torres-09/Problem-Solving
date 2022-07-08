#include<bits/stdc++.h>
using namespace std;
int n, m, k;
unsigned long long C[300][300];

void check(int a, int z, int order)
{
	if (a == 0 || z == 0)
	{
		for (long long i = 0; i < a; i++)
		{
			cout << 'a';
		}
		for (long long i = 0; i < z; i++)
		{
			cout << 'z';
		}
		return;
	}

	// 첫 번째로 a가 올 때
	if (C[a + z - 1][z] < order)
	{
		cout << 'z';
		check(a , z-1, order - C[a + z - 1][z]);
	}
	else if (C[a + z - 1][z] >= order)
	{
		cout << 'a';
		check(a - 1, z, order);
	}
}

void solve()
{
	cin >> n >> m >> k;

	C[0][1] = 1;
	for (int i = 1; i < 201; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1;j < i; j++)
		{
			C[i][j] += C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	if (k > C[n + m][m])
	{
		cout << -1;
		return;
	}

	check(n, m, k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}