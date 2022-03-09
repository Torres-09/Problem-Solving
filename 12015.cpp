#include<bits/stdc++.h>
using namespace std;
int number[1000001];
vector<int> dp;

void solve() {

	int n;
	cin >> n;

	dp.push_back(INT_MIN);
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
		if (dp.back() < number[i])
		{
			dp.push_back(number[i]);
		}
		else
		{
			auto it = lower_bound(dp.begin(), dp.end(), number[i]);
			*it = number[i];
		}
	}

	cout << dp.size() - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
