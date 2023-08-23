#include <iostream>

using namespace std;

int main()
{

	int N;
	cin >> N;
	int index = 100000;
	int *house = new int[index];
	int common_difference = 0;
	house[0] = 1;
	for (int i = 1; i<index; i++)
	{
		common_difference = common_difference + 6;
		house[i] = common_difference + house[i - 1];
	}
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i < index; i++)
	{
		if (N <= house[i])
		{
			cout << i + 1 << endl;
			break;
		}
	}
}
//a +(n-1)d - > 1+(n-1)6 - > 6n -5