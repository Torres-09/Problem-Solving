#include<bits/stdc++.h>
using namespace std;
int n, k;
int stone[50];
long long C[2501][2501];

void solve()
{
	C[0][1] = 1;

	for (int i = 1; i < 2501; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stone[i];
	}

	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += stone[i];
	}

	cin >> k;

	double up =0;

	for (int i = 0; i < n; i++)
	{
		if (stone[i] >= k)
			up += C[stone[i]][k];
	}
	double down = C[total][k];

	cout << setprecision(20);
	cout << fixed;
	cout << up / down;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}