#include<iostream>

using namespace std;

int main()
{
	unsigned int A, B, C;
	cin >> A >> B >> C;
	unsigned int N;
	if (B < C)
	{
		N = A / (C - B) + 1;
		cout << N << endl;
	}
	else if (B >= C)
		cout << "-1" << endl;
}