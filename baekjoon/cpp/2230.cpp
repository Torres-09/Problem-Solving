#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	answer = INT_MAX;
	for (int i = 0; i < n; i++) {
		int index = lower_bound(v.begin(), v.end(), m + v[i]) - v.begin();
		if (index < v.size())
			answer = min(answer, v[index] - v[i]);
	}
	cout << answer;
}