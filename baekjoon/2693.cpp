#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		
		vector<int> a;
		int num;
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());
		cout << a[7];
		cout << "\n";
		
	}
}