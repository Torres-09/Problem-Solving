#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;
	double a, b;
	int result = 0;
	cin >> N >> a >> b;
	while (1)
	{
		a = ceil(a / 2);
		b = ceil(b / 2);
		result++;
		if (a == b)
		{
			cout << result << "\n";
			break;
		}
	}
	system("pause");
}

//4 5
//2 3
//1 2
//1 1