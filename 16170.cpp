#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	cout << t->tm_year + 1900 << "\n";
	cout.width(2);
	cout.fill('0');
	cout << t->tm_mon + 1 << "\n" << t->tm_mday;
}