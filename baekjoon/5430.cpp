#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		deque<int> dq;
		string cmd;
		int n;
		string arr;
		cin >> cmd;
		cin >> n;
		cin >> arr;
		string s = "";
		bool error = false;
		for (int i = 0; i < arr.length(); i++)
		{
			if (isdigit(arr[i]))
			{
				s += arr[i];
			}
			else
			{
				if (!s.empty())
				{
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}

		int R_count = 0;
		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == 'R')
			{
				R_count++;
			}
			else if (cmd[i] == 'D')
			{
				if (dq.empty())
				{
					error = true;
					break;
				}

				if ((R_count % 2) == 0)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (error==true)
		{
			cout << "error\n";
			error = false;
		}
		else
		{
			cout << "[";
			if(!dq.empty())
			{
				if ((R_count % 2) == 0)
				{
					for (int i = 0; i < dq.size() - 1; i++)
					{
						cout << dq[i] << ',';
					}
					cout << dq.back() << "]\n";
				}
				else
				{
					for (int i = dq.size() - 1; i >0; i--)
					{
						cout << dq[i] << ',';
					}
					cout << dq.front() << "]\n";
				}
			}
			else
				cout << "]\n";
			
		}
		R_count = 0;
	}
}