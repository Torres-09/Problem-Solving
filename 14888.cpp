#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> number;
vector<int> oper;
// + - * /


int main()
{
	int N;
	cin >> N;

	int oper_num = N - 1;

	while (N--)
	{
		int num;
		cin >> num;
		number.push_back(num);
	}

	reverse(begin(number), end(number));
	
	while (oper_num--)
	{
		int num;	
		cin >> num;
		oper.push_back(num);
	}
	
}