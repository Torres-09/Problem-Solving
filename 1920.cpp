#include<bits/stdc++.h>
using namespace std;
vector<int> v;

bool b_search(int N)
{
	int first = 0;
	int last = v.size() - 1;

	while (true)
	{
		int mid = floor((first + last) / 2);

		if (N == v[mid])
			return true;
		else if (N > v[mid])
			first = mid + 1;
		else if (N < v[mid])
			last = mid;

		if (first == last)
			if (v[first] == N)
				return true;
			else
				return false;
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		
		if (binary_search(v.begin(),v.end(),number))
		{
			cout << "1\n";
		}
		else
			cout << "0\n";
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}