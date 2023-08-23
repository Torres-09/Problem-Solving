#include<bits/stdc++.h>
using namespace std;
int n, s;
int a[100001];
int sum;
int answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	answer = INT_MAX;
	int right = -1;
	for (int left=0; left < n; left++) {
		while (right < n && sum < s) {
			right++;
			if(right!=n)
				sum += a[right];
		}
		if (right == n)break;
		answer = min(right - left + 1, answer);
		sum -= a[left];
	}
	
	if (answer == INT_MAX)
		cout << 0;
	else
		cout << answer;
}