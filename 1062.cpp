#include<bits/stdc++.h>
using namespace std;
int n, k;
bool alpha[26];
vector<string> v;
int answer = 0;
// a n t a t i c a
// a n t i c 5 °³

int canRead()
{
	int result = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			char alphabet = v[i][j];
			if (alpha[alphabet - 'a'] == false)
				break;

			if (j == v[i].size() - 1)
				result++;
		}
	}


	return result;
}

void dfs(int idx, int cnt)
{
	if (cnt == k)
	{
		answer = max(answer, canRead());
		return;
	}
	else
	{
		for (int i = idx; i < 26; i++)
		{
			if (alpha[i] == true)continue;
			alpha[i] = true;
			dfs(i, cnt + 1);
			alpha[i] = false;
		}
	}
}

void solve()
{
	cin >> n >> k;

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	if (k < 5)
	{
		cout << 0;
		return;
	}

	k -= 5;


	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}

	dfs(0, 0);
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}