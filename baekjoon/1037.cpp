#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int Num;
		cin >> Num;
		num.push_back(Num);
	}
	sort(num.begin(), num.end());
	cout << num[0] * num[N - 1] << "\n";
	system("pause");
}