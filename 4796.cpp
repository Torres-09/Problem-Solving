#include<bits/stdc++.h>
using namespace std;
int l, p, v;


int main()
{
	cin >> l >> p >> v;
	int num = 1;
	while (true)
	{
		if (l == 0 && p == 0 && v == 0)
			break;



		cout << "Case " << num << ": " <<  (v / p) * l + min(v%p,l) <<"\n";

		cin >> l >> p >> v;
		num++;
	}
}