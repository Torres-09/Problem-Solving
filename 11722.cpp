#include<bits/stdc++.h>
using namespace std;
vector<int> v(1001);
vector<int> vv;
int n;

void solve()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vv.push_back(v[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < vv.size();j++) {
			if (v[i] >= vv[j])
			{
				vv[j] = v[i];
				break;
			}
			else
			{
				if (j == vv.size() - 1)
				{
					vv.push_back(v[i]);
				}
			}
		}
	}

	cout << vv.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
