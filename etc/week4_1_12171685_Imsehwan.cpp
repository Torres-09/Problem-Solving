#include<iostream>
#include<algorithm>

using namespace std;

int a, b, x, y;

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

void solve()
{
	cin >> a >> b >> x >> y;
	
	if (b > a)
		swap(a, b);

	int gcd_ab;
	gcd_ab = a - b;					//a>b

	int minus = a % gcd_ab;			//빼야하는 숫자
	int plus = (gcd_ab - minus);	//더해야 하는 숫자

	if(a-minus>0&&b-minus>0)
	{ 
		if(plus * x > minus * y)
			cout << gcd_ab << " " << minus * y << "\n";
		else
			cout << gcd_ab << " " << plus * x << "\n";
	}
	else
		cout << gcd_ab << " " << plus * x << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}