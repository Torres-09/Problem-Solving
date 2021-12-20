#include<iostream>

using namespace std;


int fibotailrec(int n, int before, int next)
{
	if (n == 0)
	{
		return before;
	}
	else return fibotailrec(n - 1, next, before + next);
}

int fibonacci(int n) {
	return fibotailrec(n, 0, 1);
}

// 1 -> N번째 fibo 수, 0 -> N-1 fibo 수 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		if (N == 0)
			cout << "1 0\n";
		else
		cout << fibonacci(N-1) << " " << fibonacci(N) << "\n";
	}
	system("pause");
}