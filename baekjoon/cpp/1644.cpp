// 투 포인터로 다시 풀어볼 것
#include<bits/stdc++.h>
using namespace std;
const int MAX = 4000001;
bool primeNum[MAX];
vector<int> v;
int cnt[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (primeNum[i] == 1)
			continue;

		for (int j = i * i; j <= MAX; j += i)
		{
			primeNum[j] = 1;
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (primeNum[i] == 0)
			v.push_back(i);
	}

	int count = 0;

	int n;
	cin >> n;


	int result = 0;

	/*int base = 0;
	int pos = 0;

	while (pos<v.size()&&(pos >= base && v[base] <=n))
	{
		if (result < n)
		{
			result += v[pos];
			pos++;
		}
		else if (result > n)
		{
			result -= v[base];
			base++;
		}
		else if (result == n)
		{
			result += v[pos];
			count++;
		}

		if (v[base] == n)
		{
			count++;
			break;
		}
	}*/

	for (int i = 0; i < v.size(); i++)
	{
		result = 0;
		for (int j = i;j < v.size(); j++)
		{
			result += v[j];
			if (result > MAX)
			{
				break;
			}
			else
			{
				cnt[result]++;
			}
		}
	}

	cout << cnt[n];
}