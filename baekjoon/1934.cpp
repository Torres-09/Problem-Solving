#include<iostream>

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
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << (a * b) / gcd(a, b) << "\n";
	}
}