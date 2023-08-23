// 가장 긴 증가하는 부분수열 5
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005];
int dp[1000005];
vector<int> v;
stack<int> ans;
int n;
int cnt;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	v.push_back(a[1]);

	for (int i = 2; i <= n; i++)
	{
		if (v[cnt] < a[i])
		{
			v.push_back(a[i]);
			cnt++;
			dp[i] = cnt;
		}
		else
		{
			int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[pos] = a[i];
			dp[i] = pos;
		}
	}

	// 이렇게 하면 size는 맞을 지 몰라도 뒤에 더 작은 수가 나오면 제대로 수열이 안 나온다. check 가 필요함.
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/

	for (int i = n; i >= 0; i--)
	{
		if (dp[i] == cnt)
		{
			ans.push(a[i]);
			cnt--;
		}
	}

	cout << ans.size() << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}