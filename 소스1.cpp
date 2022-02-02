// ≈‰∏∂≈‰
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int main()
{

	tuple<int, int, int> tp;
	tp = make_tuple(10, 10, 10);
	cout << get<0>(tp) << "\n";
}