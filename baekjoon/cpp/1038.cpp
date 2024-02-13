#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v[12];
	v[0] = { 0,1,2,3,4,5,6,7,8,9 };

	// 자리수
	for (int i = 0; i < 10; i++)
	{
		//자리수의 내림수 개수
		for (int j = 0; j < v[i].size(); j++)
		{
			// 0 ~ 8
			for (int k = 0; k < 9; k++)
			{
				if (v[i][j] % 10 > k)
				{
					int num;
					num = v[i][j] * 10 + k;
					v[i + 1].push_back(num);
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	int n;
	cin >> n;


	if (n == 1022)
	{
		cout << "9876543210";
		return 0;
	}

	int ans = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			ans++;

			if (ans == n)
			{
				cout << v[i][j];
				return 0;
			}
		}
	}
	cout << -1;
}