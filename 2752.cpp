#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		int number;
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	for (int i =0;i<3;i++)
		cout << v[i] << " ";
}