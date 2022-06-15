#include<bits/stdc++.h>
using namespace std;
double ans = 0;

void plusminus(char a)
{
	if (a == '-')
		ans -= 0.3;
	else if (a == '+')
		ans += 0.3;
}

int main()
{
	string s;
	cin >> s;
	cout << fixed << setprecision(1);

	if (s[0] == 'A')
		ans = 4;
	else if (s[0] == 'B')
		ans = 3;
	else if (s[0] == 'C')
		ans = 2;
	else if (s[0] == 'D')
		ans = 1;
	else
	{
		cout << 0.0;
		return 0;
	}


	plusminus(s[1]);
	
	
	cout << ans;
}