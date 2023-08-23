#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
bool primeNum[MAX];

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
	int n=1;
	cin >> n;
	primeNum[1] = 1;
	while (n!=0)
	{
		for (int i = n; i >= n/2; i--)
		{
			if (primeNum[i] != 1)
				if (primeNum[n - i] != 1)
				{
					cout << n << " = " << n - i << " + " << i << "\n";
					break;
				}
		}
		cin >> n;
	}


}