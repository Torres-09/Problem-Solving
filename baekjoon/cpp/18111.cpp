#include<bits/stdc++.h>
using namespace std;
long long n, m, b;
int pl[500][500];
int ans[257];

void solve()
{
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> pl[i][j];
		}
	}


	int answer = INT_MAX;
	int h = INT_MIN;
	for(int k=0;k<=256;k++)
	{
		int b_copy = b;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pl[i][j] - k > 0)
				{
					ans[k] += (pl[i][j] - k) * 2;
					b_copy += (pl[i][j] - k);
				}
				else if (pl[i][j] - k < 0)
				{
					ans[k] += (k - pl[i][j]);
					b_copy -= (k - pl[i][j]);
				}
			}
		}

		if (b_copy < 0)
			ans[k] = INT_MAX;

		if (answer >= ans[k])
		{
			if (h < k)
			{
				answer = ans[k];
				h = k;
			}
		}
	}

	cout << answer << " " << h;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}