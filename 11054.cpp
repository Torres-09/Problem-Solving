#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[1001];
vector<int> dp1(1001);
vector<int> dp2(1001);
vector<int> dp3(1001);
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
				if (dp1[i] <= dp1[j])
				{
					dp1[i] = dp1[j] + 1;
				}
			}
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] > a[j])
			{
				if (dp2[i] <= dp2[j])
				{
					dp2[i] = dp2[j] + 1;
				}
			}
		}
	}

	for (int i = 0; i < 1001; i++)
	{
		dp3[i] = dp1[i] + dp2[i];
	}

	cout << *max_element(dp3.begin(), dp3.begin() + n) + 1;
}