#include<bits/stdc++.h>
using namespace std;

long long solve() {
	long long ans = 0;
	long long n, m, d;
	cin >> n >> m >> d;
	deque<pair<long long,long long>> jandi;

	int num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			jandi.push_back({ num,0 });
		}
	}

	vector<long long> gas;
	for (int i = 0; i < d; i++)
	{
		cin >> num;
		gas.push_back(num);
	}

	sort(jandi.begin(), jandi.end(),greater<>());

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < gas[i]; j++)
		{
			ans += (jandi.front().first + i - jandi.front().second) * (i + 1);
			jandi.push_back({ 0,i });
			jandi.pop_front();
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	int seq = 1;

	while (t--)
	{
		long long result = solve();
		cout << "#" << seq << " " << result << "\n";
		seq++;
	}
}
//100Á¡