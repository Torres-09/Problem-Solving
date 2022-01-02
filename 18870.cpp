#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v, vv;
int n;

int main()
{
	cin >> n;
	int number;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		v.push_back(number);
		vv.push_back(number);
	}
	
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin() << " ";
	}
}