#include<bits/stdc++.h>
using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(1, INT_MAX);

	cout << dis(gen);
}