#include<bits/stdc++.h>
using namespace std;
int t, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	char cmd;
	long long num;
	while (t--) {
		multiset<long long> s;
		cin >> k;
		while (k--) {
			cin >> cmd;
			cin >> num;
			if (cmd == 'I') {
				s.insert(num);
			}
			else if (cmd == 'D') {
				if (s.empty())
					continue;

				if (num == -1) {
					s.erase(s.begin());
				}
				else {
					s.erase(--s.end());
				}
			}
		}

		if (s.empty())
			cout << "EMPTY\n";
		else {
			cout << *prev(s.end()) << " " << *s.begin() << "\n";
		}
	}
}