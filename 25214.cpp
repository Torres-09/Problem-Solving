#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int max_ele = a[0];
	int min_ele = a[0];
	int min_temp = a[0];

	for (int i = 0; i < n; i++)
	{
		if (max_ele - min_ele < a[i] - min_temp)
		{
			max_ele = a[i];
			min_ele = min_temp;
		}

		if (a[i] > max_ele)
			max_ele = a[i];
		

		if (a[i] < min_temp)
			min_temp = a[i];

		cout << max_ele - min_ele << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}