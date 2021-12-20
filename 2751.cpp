#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
	int N;
	cin >> N;
	int* number = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}
	
	sort(number, number + N);

	for (int i = 0; i < N; i++) {
		cout << number[i] << "\n";
	}
	system("pause");
}