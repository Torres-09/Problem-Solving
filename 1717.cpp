#include<bits/stdc++.h>
using namespace std;
int n, m;
int cmd, a, b;
int num[1000001];

int find(int c)
{
	if (num[c] == c)return c;
	else 
		return num[c] = find(num[c]);
}

void union_function(int n1, int n2)
{
	int aRoot = find(n1);
	int bRoot = find(n2);
	num[aRoot] = bRoot;
}

void solve()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		num[i] = i;
	}


	while (m--)
	{
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			union_function(b, a);
		}
		else if (cmd == 1)
		{
			if (find(a) == find(b))
			{
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}