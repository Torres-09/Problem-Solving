#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int tree[500005];

int sum(int i)
{
	int result = 0;
	while (i > 0)
	{
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

void solve()
{
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		v.push_back({ num,i });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		v[i].first = i + 1;
		swap(v[i].first, v[i].second);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		int temp = v[i].second;
		cout << (i + 1) - sum(temp - 1) << "\n";
		update(temp, 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}