#include<bits/stdc++.h>
using namespace std;
int n, m;
int cnt;
bool vis[21];
vector<int> v;

void func(int k, int tot) {
	if (k == n) {
		if (tot == m)cnt++;
		return;
	}

	func(k + 1,tot +v[k]);
	func(k + 1, tot);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	func(0,0);

	if (m == 0)cnt--;
	cout << cnt;
}