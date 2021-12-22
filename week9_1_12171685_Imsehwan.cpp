// divide and conquer
#include<iostream>
#include<math.h>
#define ll long long

using namespace std;

int t;
ll x, n, m;

pair<ll,ll> geoserise(ll x, ll n)
{
	if (n == 1)
		return { x%m,x%m };
	
	pair<ll, ll> half = geoserise(x, floor(n / 2));
	ll exp = half.first;
	ll sum = half.second;
	
	if (n % 2 == 0)
		return { (exp*exp) % m,((1 + exp)*sum) % m };
	else
		return { (x*exp*exp) % m,(x + x*(1 + exp)*sum) % m };
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> x >> n >> m;

		pair<ll, ll> answer = geoserise(x, n);

		cout << answer.second << "\n";
	}
}