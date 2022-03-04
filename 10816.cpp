#include<bits/stdc++.h>
using namespace std;
vector<int > v;
int arr[20000001] = { 0 };
const int num = 10000000;

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;

		if(arr[number+ num]==0)
			v.push_back(number);

		arr[number + num] += 1;
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		if (binary_search(v.begin(), v.end(), number))
			cout << arr[number + num] << " ";
		else
			cout << "0 ";
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}