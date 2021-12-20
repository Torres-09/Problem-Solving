#include<iostream>

using namespace std;

int D(int n)
{
	int Dn = n;
	while (n > 0)
	{
		Dn += (n % 10);
		n /= 10;
	}
	return Dn;
}

int main()
{
	bool arr[10000];
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = true;
	}
	for (int i = 1; i < 10000; i++)
	{
		if (D(i) < 10000)
			arr[D(i)] = false;
	}
	
	for (int i = 1; i < 10000; i++)
	{
		if (arr[i] == true)
			cout << i << endl;
	}

	system("pause");
}