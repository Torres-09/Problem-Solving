//¸µ
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
	int N;
	cin >> N;
	
	int ring_size = N;
	int *ring = new int[ring_size-1];
	int i = 0;
	while (N--)
	{
		cin >> ring[i];
		i++;
	}
	for (int i = 1; i < ring_size; i++)
	{
		cout << ring[0] / gcd(ring[0], ring[i]) << "/" <<  ring[i] / gcd(ring[0], ring[i]) << "\n";
	}
	system("pause");
}