#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	
	
	vector<int> house;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		house.push_back(number);
	}

	sort(house.begin(), house.end());

	int left = 0;
	int right = house.back();
	

	while (left<=right)
	{
		int ip_cnt = 1;
		int pre_index = 0;
		int mid = (left + right) / 2;

		for (int i = 1; i < n; i++)
		{
			if (house[i] - house[pre_index] >= mid)
			{
				pre_index = i;
				ip_cnt++;
			}
		}

		if (ip_cnt >= c)
			left = mid + 1;
		else right = mid - 1;
	}

	cout << right;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}