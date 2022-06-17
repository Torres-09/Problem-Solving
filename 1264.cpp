#include<bits/stdc++.h>
using namespace std;

int main()
{
	set<char> Set;
	char k[10] = { 'a', 'e', 'i', 'o', 'u' ,'A','E','I','O','U' };
	for (int i = 0; i < 10; i++)
	{
		Set.insert(k[i]);
	}

	string s;
	while (1)
	{
		int ans = 0;
		getline(cin, s);

		if (s == "#")
			break;

		for (int i = 0; i < s.size(); i++)
		{
			if (!(Set.find(s[i]) == Set.end()))
				ans++;
		}

		cout << ans << "\n";
	}
}