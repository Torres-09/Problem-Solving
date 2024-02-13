#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int *seq = new int[n + 1];
	vector<int>v;
	string result = "";
	for (int i = 1; i < n + 1; i++)
	{
		cin >> seq[i];
	}


	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		result += "+";

		while (!v.empty() && v.back() == seq[j])
		{
			v.pop_back();
			result += "-";
			j++;
		}
	}

	if (j == n + 1)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}
	else
	{
		cout << "NO\n";
	}
}