#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	int d, f;

	cin >> a >> b >> c >> d >> f;

	cout << min(min(a,b), c) + min(d, f) - 50;
}