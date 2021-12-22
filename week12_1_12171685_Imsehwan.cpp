// 

#include<iostream>
#include<vector>

using namespace std;
vector<int> v[100];

void init() {
	for (int i = 0; i < 100; i++) {
		v[i].clear();
	}
}

int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		init();
		int n;
		cin >> n;

		int a;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> a;
				v[i].push_back(a);
			}
		}

		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; i != j; j++)
			{

				if (v[i][j] < v[i][j + 1])
					v[i - 1][j] += v[i][j];
				else
					v[i - 1][j] += v[i][j + 1];
			}
		}

		cout << v[0][0] << "\n";
	}
}