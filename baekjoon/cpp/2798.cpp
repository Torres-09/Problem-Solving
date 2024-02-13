#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int *p = new int[N];

	int M;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}

	int sum = 0;
	for (int a = 0; a < N - 2; a++)
	{
		for (int b = a+1; b < N - 1; b++)
		{
			for (int c = b+1; c < N; c++)
			{
				if (p[a] + p[b] + p[c] > sum) {
					if(p[a] + p[b] + p[c]<=M)
					sum = p[a] + p[b] + p[c];
				}
			}
		}
	}
	cout << sum << endl;
	system("pause");
}