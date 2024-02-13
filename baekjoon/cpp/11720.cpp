#include<iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;
	char* A = new char[N];
	cin >> A;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = sum + (int)(A[i]-48);
	}
	cout << sum << endl;
}