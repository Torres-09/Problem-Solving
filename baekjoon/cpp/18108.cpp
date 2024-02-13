// 1998년생인 내가 태국에서는 2541년생?!
#include<iostream>
using namespace std;

int main()
{
	const int translate = 2541 - 1998;
	int year;
	cin >> year;
	cout << year - translate;
}