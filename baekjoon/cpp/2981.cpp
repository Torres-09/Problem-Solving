//°Ë¹®
#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int A, int B)
{
	int c;
	while (B != 0)
	{
		c = A % B;
		A = B;
		B = c;
	}

	return A;

}

int main()
{
	int T;
	cin >> T;
	int arr_size = T;
	int *N = new int[arr_size];
	while (T--)
	{
		cin >> N[T];
	}
	
	
	for (int i = 0; i < arr_size - 1; i++)
	{

	}

	system("pause");
}