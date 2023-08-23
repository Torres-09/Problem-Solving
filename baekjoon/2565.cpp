#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int n;
vector<int> dp(501);

int main()
{
	cin >> n;
	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				if (dp[i] <= dp[j])
					dp[i] = dp[j] + 1;
			}
		}
	}

	cout <<  n - 1 - *max_element(dp.begin(), dp.begin() + n);
}