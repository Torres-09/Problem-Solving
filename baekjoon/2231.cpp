#include<iostream>

using namespace std;

int D(int n)
{
	int Dn = n;
	while (n > 0)
	{
		Dn += (n % 10);
		n /= 10;
	}
	return Dn;
}

int main()
{
	int N;
	cin >> N;
	int *p = new int[N];
	int result=0;

	for (int i = 0; i < N; i++)
	{
		p[i] = D(i);
	}

	for (int i = 0; i < N; i++)
	{
		if (p[i] == N) {
			result = i;
			break;
		}
	}
	if (result != 0)
		cout << result << endl;
	else
		cout << 0 << endl;
	
}