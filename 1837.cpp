#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1000001;
bool primeNum[MAX];
vector<long long> prime;
long long answer = 0;
long long result = 0;
string p;
long long k = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(primeNum, 0, sizeof(primeNum));

	for (long long i = 2; i <= sqrt(MAX); i++)
	{
		if (primeNum[i] == 1)
			continue;

		for (long long j = i * i; j < MAX; j += i)
		{
			primeNum[j] = 1;
		}
	}
	
	for (long long i = 2; i < MAX; i++)
	{
		if (primeNum[i] == 0)
			prime.push_back(i);
	}

	cin >> p >> k;

	for (int i = 0; i < prime.size(); i++)
	{
		result = 0;

		for (int j = 0; j < p.size(); j++)
		{
			result = (result * 10 + p[j] - '0') % prime[i];
		}

		if (result == 0) {
			answer = prime[i];
			break;
		}
	}

	if (answer < k)
		cout << "BAD " << answer;
	else
		cout << "GOOD";
}