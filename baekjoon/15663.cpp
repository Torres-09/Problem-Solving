#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int can_Use[10001];
int ans[9];


// 1 7 9 9

void search(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		
		if (can_Use[v[i]]&&temp!=v[i])
		{
			temp = v[i];
			ans[x] = v[i];
			can_Use[v[i]]--;
			search(x + 1);
			can_Use[v[i]]++;
		}
	}
}

void solve()
{
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
		can_Use[num]++;
	}

	sort(v.begin(), v.end());
	search(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}