#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[1001];
vector<int> dp(1001);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (dp[i] <= dp[j])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	cout << *max_element(dp.begin(), dp.begin() + n) + 1;
}