#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>> pq;
int answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() >= 2) {
		int num1 = pq.top(); pq.pop();
		int num2 = pq.top(); pq.pop();
		answer += (num1 + num2);
		if (pq.empty())break;
		pq.push(num1 + num2);
	}

	cout << answer;
}