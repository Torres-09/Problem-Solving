#include<bits/stdc++.h>
using namespace std;
int n, k;
int primeNum[1001];

void solve()
{
	cin >> n >> k;
	memset(primeNum, 1, sizeof(primeNum));
	int count = 0;

	for (int i = 2; i <= n; i++)
	{
		if (primeNum[i] == 0)
			continue;

		primeNum[i] = 0;
		count++;

		if (count == k)
		{
			cout << i;
			return;
		}

		for (int j = i * i; j <= n; j+=i)
		{
			if (primeNum[j] == 0)
				continue;

			primeNum[j] = 0;
			count++;

			if (count == k)
			{
				cout << j;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}