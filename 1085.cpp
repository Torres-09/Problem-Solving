#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int result1;
	int result2;
	int result3;
	int result4;
	result1 = x;
	result2 = y;
	result3 = h - y;
	result4 = w - x;
	cout << min(min(result1, result2), min(result3, result4)) << "\n";
	
}