#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;

int gcd(int num1, int num2)
{
	int temp;

	if (num1 < num2)
		swap(num1, num2);

	while (num2 != 0)
	{
		temp = num1;
		num1 = num2;
		num2 = temp % num2;
	}

	return num1;
}

void solve()
{
	cin >> a >> b >> c >> d;

	int up;
	int down;
	up = a * d + c * b;
	down = b * d;
	int temp = gcd(up,down);

	cout << up / temp << " " << down / temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}