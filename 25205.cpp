#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;
	char ss[14] = { 'r','s','e','f','a','q','t','d','w','c','z','v','x','g' };
	for (int i = 0; i < 14; i++)
	{
		if (s[s.size() - 1] == ss[i])
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}