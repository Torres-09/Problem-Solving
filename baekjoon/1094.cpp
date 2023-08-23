#include<iostream>

using namespace std;
int za[7] = { 64, 32 , 16,8,4,2,1 };

int solve(int N)
{
	int result = 0;
	for (int i = 0; i < 7; i++)
	{
		if (N >= za[i]) {
			N = N - za[i];
			result++;
		}
	}
	return result;
}

int main()
{
	

	int N;
	cin >> N;
	cout << solve(N) << "\n";
	system("pause");
}