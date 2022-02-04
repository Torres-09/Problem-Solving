// µ¿Àü 0
#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int a[11];
int temp;
int temp_2;
int result = 0;

void solve()
{
	temp = k / a[0];

	for (int i = 1; i < n; i++)
	{
		if (k / a[i] < 1)
		{
			temp_2 = i - 1;
			break;
		}

		temp = min(k / a[i], temp);
		temp_2 = i;
	}

	k = k - (a[temp_2] * temp);
	result += temp;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (k)
	{
		solve();
	}

	cout << result << "\n";
}