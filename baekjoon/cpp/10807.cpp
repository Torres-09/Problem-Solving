#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	int a;
	cin >> a;
	int ans = 0;
	for (int i =0;i<v.size();i++)
	{
		if (a == v[i])
		{
			ans++;
		}
	}
	cout << ans;
}