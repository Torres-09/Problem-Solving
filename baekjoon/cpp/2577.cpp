#include<iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int MULTIPLE = A*B*C;
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		if (MULTIPLE == 0)
			break;
		arr[MULTIPLE % 10]++;
		MULTIPLE = (MULTIPLE - (MULTIPLE % 10)) / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}