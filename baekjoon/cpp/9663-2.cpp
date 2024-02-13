#include<iostream>

using namespace std;
int N;
int result = 0;
bool *col;
bool *dup;
bool *ddown;

void solve(int n)
{
	if (n >= N) {
		result++;
		return;
	}


	for (int i = 0; i < N; i++)
	{
		if (col[i])continue;
		if (dup[n + i] || ddown[N - 1 + (n - i)])continue;

		col[i] = true;
		dup[n + i] = true;
		ddown[N - 1 + (n - i)] = true;

		solve(n + 1);

		col[i] = false;
		dup[n + i] = false;
		ddown[N - 1 + (n - i)] = false;
	}
}

int main()
{
	
	cin >> N;

	col = new bool[N];
	dup = new bool[2 * N - 1];
	ddown = new bool[2 * N - 1];
	for (int i = 0; i < N; i++)
	{
		col[i] = false;
	}

	for (int i = 0; i < 2 * N - 1; i++)
	{
		dup[i] = false;
		ddown[i] = false;
	}

	solve(0);
	cout << result << "\n";
	system("pause");

}


