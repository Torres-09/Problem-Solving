#include<iostream>
#include<vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> jupa;

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		jupa.push_back(x);
	}

	for (int i = 1; i < n; i++)
	{
		if (jupa[0] == jupa[i])
		{
			for (int j = 0; j < jupa.size(); j++)
			{
				if (jupa.size() == i + j)
				{
					for (int k = 0; k < i; k++)
					{
						cout << jupa[k] << " ";
					}
					cout << "\n";
					return;
				}
				if (jupa[j] != jupa[i + j])
					break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << jupa[i] << " ";
	}
	cout << "\n";
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}