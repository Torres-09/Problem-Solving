#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> sum;
bool vis[1001];
int temp;
int answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum.push_back(v[i] + v[j]);
		}
	}
	sort(sum.begin(), sum.end());
	sum.erase(unique(sum.begin(), sum.end()), sum.end());

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(sum.begin(), sum.end(), v[i] - v[j])) {
				cout << v[i];
				return 0;
			}
		}
	}
}