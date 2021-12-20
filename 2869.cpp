#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double A, B, V;
	cin >> A >> B >> V;
	if (V == A)
	{
		cout << 1 << endl;
		system("pause");
		return 0;
	}
	if ((V - A) / (A - B) <= 1) {
		cout << 2 << endl;
		system("pause");
		return 0;
	}
	cout << (int)(ceil((V - A) / (A - B)) + 1) << endl;
	system("pause");
}

/*
int A, B, V;
cin >> A >> B >> V;
int Day = 0;
while (V)
{
V = V - A;
Day++;
if (V <= 0) {
break;
}
V = V + B;
}
cout << Day << endl;
*/