#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	vector<string> v;
	string s;

	
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}