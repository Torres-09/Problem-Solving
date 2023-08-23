#include<iostream>
using namespace std;
long long p[101] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

long long solution(int n)
{
	if (n < 10)
		return p[n];

	else
	{
		if (p[n-2] == 0)
		{
			p[n - 2] = solution(n -2);
		}
		if (p[n - 3] == 0)
		{
			p[n - 3] = solution(n -3);
		}

		return p[n - 2] + p[n - 3];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;

		cout << solution(n-1) << "\n";
	}
	
	
}