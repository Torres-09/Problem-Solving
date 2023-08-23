#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> s1;
unordered_map<int, int> s2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int num;
	for (int i = 0; i < a; i++)
	{
		cin >> num;
		s1.insert({ num,i });
	}

	for (int i = 0; i < b; i++)
	{
		cin >> num;
		s2.insert({ num,i });
	}

	int size_1 = 0;
	int size_2 = 0;

	for (pair<int, int> elem: s1)
	{
		if ((s2.find(elem.first) == s2.end()))
			size_1++;
	}

	for (pair<int, int> elem : s2)
	{
		if ((s1.find(elem.first) == s1.end()))
			size_2++;
	}

	cout << size_1 + size_2;
}