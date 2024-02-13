#include<bits/stdc++.h>
using namespace std;
int l, c;
vector<char> v1;
bool consonant[16];
char answer[16];

void check(int pos, int prev, int conso_count, int vowel_count)
{
	if (pos == l && conso_count >= 1 && vowel_count >= 2)
	{
		for (int i = 0; i < l; i++)
		{
			cout << answer[i];
		}
		cout << "\n";
		return;
	}

	for (int i = prev + 1; i < c; i++)
	{
		char now = v1[i];
		answer[pos] = now;

		if (consonant[i])
			check(pos + 1, i, conso_count + 1, vowel_count);
		else
			check(pos + 1, i, conso_count, vowel_count + 1);
	}
}

void solve()
{
	cin >> l >> c;
	char al;

	for (int i = 0; i < c; i++)
	{
		cin >> al;
		v1.push_back(al);
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == 'a' || v1[i] == 'e' || v1[i] == 'i' || v1[i] == 'o' || v1[i] == 'u')
			consonant[i] = true;
	}

	check(0, -1, 0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}