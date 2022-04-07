#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a[1001];

void solve()
{
	int n;
	cin >> n;

	v.push_back(INT_MIN);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (v.back() < a[i])
			v.push_back(a[i]);
		else
		{
			auto iter = lower_bound(v.begin(), v.end(), a[i]);
			*iter = a[i];
		}
	}

	cout << v.size() - 1 << "\n";
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	solve();
}