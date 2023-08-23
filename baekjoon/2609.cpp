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
	unsigned int A, B;
	cin >> A >> B;

	cout << gcd(A, B) << "\n" <<  (A * B) / gcd(A, B);
	system("pause");
}
