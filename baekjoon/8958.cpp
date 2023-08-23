#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string OX;
		int score = 0;
		cin >> OX;
		for (int i = 0; i < OX.length(); i++)
		{
			for (int j = 1; i < OX.length(); j++)
			{
				if (OX.at(i) == 'O')
				{
					score = score + j;
					i++;
				}
				else
				{
					break;
				}
			}
		}
		cout << score << endl;
	}
}