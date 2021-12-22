#include<iostream>
#include<queue>
#include<string>



using namespace std;

void solve()
{
	int n;
	int m;

	queue<string> says;
	queue<string> arr[20];
	string words;

	cin >> n >> m;
	int count = n;
	for (int i = 0; i < m; i++)
	{
		cin >> words;
		says.push(words);
	}

	int number = 0;

	while (count--)
	{
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> words;
			arr[number].push(words);
		}
		number++;
	}

	int alpha = 0;


	while (!says.empty())
	{
		bool check = true;

		for (int i = 0; i < n; i++)
		{
			if (says.front() == arr[i].front())
			{
				says.pop();
				arr[i].pop();
				check = false;
				alpha++;
				break;
			}
		}

		if (check == true)
			break;

	}
	


	if (says.empty())
		cout << "1\n";
	else
		cout << "0\n";
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