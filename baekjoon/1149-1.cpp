#include<iostream>
#include<algorithm>
using namespace std;
int n;
int house[1001][3];

int main()
{
	cin >> n;
	int red, green, blue;

	for (auto i : house[0])
		house[0][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> red >> green >> blue;

		house[i][0] += min(house[i - 1][1], house[i - 1][2]) + red;
		house[i][1] += min(house[i - 1][0], house[i - 1][2]) + green;
		house[i][2] += min(house[i - 1][0], house[i - 1][1]) + blue;
	}

	cout << min(min(house[n][0], house[n][1]),min(house[n][1],house[n][2]));
}