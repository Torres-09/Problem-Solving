#include<iostream>
#include<vector>

using namespace std;
vector <vector<int>> v;

int main()
{
	
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		vector<int> v2(i);
		v.push_back(v2);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}

	int result = 0;
	int result_temp = 0;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << v[i][0] << " ";
		}
		cout << "\n";
	}
	system("pause");
}