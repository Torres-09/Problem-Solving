#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string arr;
		stack<char> sta;

		cin >> arr;
		for (int i = 0; i < arr.size(); i++)
		{
			sta.push(arr[i]);
		}

		int check = 0;
		int stop = 0;
		while (!sta.empty())
		{
			if (sta.top() == ')')
			{
				check++;
				sta.pop();
			}
			else
			{
				check--;
				sta.pop();
			}

			if (check < 0)
			{
				stop++;
				break;
			}
		}

		if (check == 0&&check==0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}