#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	string N;
	cin >> N;
	sort(N.begin(), N.end(),compare);
	cout << N << "\n";
	system("pause");
}