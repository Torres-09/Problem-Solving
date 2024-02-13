// 소수 찾기
#include<bits/stdc++.h>
using namespace std;
long long k, n;
vector<long long> v;
priority_queue<long long,vector<long long>,greater<long long>> pq;

void solve()
{
	cin >> k >> n;
	long long num;

	for (long long i = 0; i < k; i++)
	{
		cin >> num;
		v.push_back(num);
		pq.push(num);
	}

	long long answer = 0;

	for (long long i = 0; i < n; i++)
	{
		answer = pq.top();
		pq.pop();

		for (long long j = 0; j < k; j++)
		{
			long long val = answer * v[j];
			pq.push(val);

			if (answer % v[j] == 0)
				break;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}