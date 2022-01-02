#include<iostream>
#include<vector>
using namespace std;
long long a[5][5];
int n;
long long b;
long long result[5][5];

int solution(int n, int k, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int q = 0; q < m; q++)
			{
				result[i][j] += a[i][q] * a[q][j];
			}
		}
	}
}

void solution(int x, int size)
{
	
}

int main()
{
	cin >> n >> b ;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}


}