#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
	string s = "banana";
	vector<int> answer;
	for (int i = 0; i < s.size(); i++)
	{
		answer.push_back(-1);
		for (int j = 0; j < i; j++)
		{
			if (s[i] == s[j])
				answer[i] = i - j;
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}