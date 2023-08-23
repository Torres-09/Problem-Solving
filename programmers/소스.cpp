#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int main()
{
	int N;
	int *number;
	cin >> N;
	number = new int[N];
	for (int i = 0; i<N; i++)
	{
		cin >> number[i];
	}
	sort(number, number+N);
	cout << number[0] << " " << number[N-1] << "\n";
	system("pause");
}