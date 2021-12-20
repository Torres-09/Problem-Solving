#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int result = 0; // ºÀÁö °³¼ö

	result = (N / 5);
	N = N % 5;
	while (N) {
		if (N % 3 != 0)
		{
			if (result == 0)
			{
				cout << "-1" << endl;
				break;
			}
			N = N + 5;
			result = result - 1;
		}
		else
		{
			result += N / 3;
			N = N % 3;
		}
	}
	if (result != 0) {
		cout << result << endl;
	}
	system("pause");
}