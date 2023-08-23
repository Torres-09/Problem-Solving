#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long cnt[1001];
long long answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(cnt, 0, sizeof(cnt));

	cin >> n >> m;
	int num;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		cnt[sum % m]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		answer += cnt[i] * (cnt[i]-1) / 2;
	}

	cout << cnt[0] + answer;
}