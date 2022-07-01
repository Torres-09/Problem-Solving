#include<bits/stdc++.h>
using namespace std;
int alpha[26];

int main() {
	memset(alpha, 0, sizeof(alpha));
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int num = 0;
		num = s[i] - 'a';
		alpha[num] += 1;
	}

	for (int i : alpha)
		cout << i << " ";

}
