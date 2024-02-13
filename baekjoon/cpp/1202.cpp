#include<bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> jew[1000001];
multiset<int> bag;
int weight;
int price;
long long answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight >> price;
		jew[i] = { price,weight };
	}
	sort(jew, jew + n);
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		bag.insert(num);
	}

	for (int i = n - 1; i >= 0; i--) {
		int p, w;
		tie(p, w) = jew[i];
		auto iter = bag.lower_bound(w);
		if (iter == bag.end())continue;
		answer += p;
		bag.erase(iter);
	}
	cout << answer;
}