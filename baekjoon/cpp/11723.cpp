#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<int> allSet = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	int m;
	cin >> m;

	string s;
	set<int> Set;
	int num;

	while (m--)
	{
		cin >> s;

		if (s == "add")
		{
			cin >> num;
			Set.insert(num);
		}
		else if (s == "remove")
		{
			cin >> num;
			if (Set.find(num) == Set.end())
				continue;

			Set.erase(num);
		}
		else if (s == "check")
		{
			cin >> num;
			cout << Set.count(num) << "\n";
		}
		else if (s == "toggle")
		{
			cin >> num;
			if (Set.count(num) == 1)
			{
				Set.erase(Set.find(num));
			}
			else
			{
				Set.insert(num);
			}
		}
		else if (s == "all")
		{
			Set = allSet;
		}
		else if (s == "empty")
		{
			Set.clear();
		}
	}
}