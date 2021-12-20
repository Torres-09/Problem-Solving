#include<iostream>
#include<vector>

using namespace std;

long long sum(std::vector<int> &a)
{
	int SUM = 0;
	for (int i = 0; i <= a.size(); i++)
	{
		SUM += *(a.end()-1);
		a.pop_back();
	}
	return SUM;
}

int main()
{
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator iter;
	iter = v.end();
	cout << *(v.begin()) << endl;
	cout << *(v.end()-1)<< endl;
	cout << *(v.rbegin()) << endl;
	cout << *(v.rend() -1) << endl;
	system("pause");
}