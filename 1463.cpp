#include<iostream>
#include<algorithm>

using namespace std;
int result1 = 0;
int result2 = 1;
int result3 = 2;

void solve(int N)
{
	if (N == 1)
		return;

	if (N % 3 == 0)
	{
		N = N / 3;
		result1++;
		solve(N);
		return;
	}
	else if (N % 2 == 0)
	{
		N = N / 2;
		result1++;
		solve(N);
		return;
	}
	else
	{
		N = N - 1;
		result1++;
		solve(N);
		return;
	}
}

void solve1(int N)
{
	if (N == 1)
		return;

	if (N % 3 == 0)
	{
		N = N / 3;
		result2++;
		solve1(N);
		return;
	}
	else if (N % 2 == 0)
	{
		N = N / 2;
		result2++;
		solve1(N);
		return;
	}
	else
	{
		N = N - 1;
		result2++;
		solve1(N);
		return;
	}
}
void solve2(int N)
{
	if (N == 1)
		return;

	if (N % 3 == 0)
	{
		N = N / 3;
		result3++;
		solve2(N);
		return;
	}
	else if (N % 2 == 0)
	{
		N = N / 2;
		result3++;
		solve2(N);
		return;
	}
	else
	{
		N = N - 1;
		result3++;
		solve2(N);
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	if (N == 1)
	{
		cout << 1 << "\n";
		return 0;
	}
	if (N == 2)
	{
		cout << 1 << "\n";
		return 0;
	}
	solve(N);
	solve1(N - 1);
	solve2(N - 2);
	int end;
	end = min(result1, result2);
	end = min(end, result3);
	cout << end << "\n";
	system("pause");
}