#include<bits/stdc++.h>
using namespace std;
vector<string> v;
stack<long long> s;

void solve()
{
	long long num;
	long long num2;

	for (long long i = 0; i < v.size()-1; i++)
	{
		if (v[i] == "NUM")
		{
			i++;
			s.push(stol(v[i]));
		}
		else if (v[i] == "POP")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			s.pop();
		}
		else if (v[i] == "INV")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			num *= -1;
			s.pop();
			s.push(num);
		}
		else if (v[i] == "DUP")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			s.push(num);
		}
		else if (v[i] == "SWP")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();

			s.push(num);
			s.push(num2);
		}
		else if (v[i] == "ADD")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();

			num += num2;
			if (abs(num) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}

			s.push(num);
		}
		else if (v[i] == "SUB")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();

			num2 -= num;
			s.push(num2);

			if (abs(num2) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}

		}
		else if (v[i] == "MUL")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();

			num *= num2;
			if (abs(num) > 1000000000)
			{
				cout << "ERROR\n";
				return;
			}

			s.push(num);
		}
		else if (v[i] == "DIV")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num = s.top();
			if (num == 0)
			{
				cout << "ERROR\n";
				return;
			}

			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();

			long long temp1 = num;
			long long temp2 = num2;

			num2 = abs(num2) / abs(num);

			if(temp1*temp2 < 0)
				s.push(num2* -1);
			else
				s.push(num2);
		}
		else if (v[i] == "MOD")
		{
			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}
			num = s.top();

			if (num == 0)
			{
				cout << "ERROR\n";
				return;
			}
			s.pop();

			if (s.empty())
			{
				cout << "ERROR\n";
				return;
			}

			num2 = s.top();
			s.pop();
				
			long long temp1 = num;
			long long temp2 = num2;

			num2 = abs(num2) % abs(num);
				
			if (temp2 < 0)
				s.push(num2 * -1);
			else s.push(num2);
		}
	}
	
	if (s.size() != 1)
	{
		cout << "ERROR\n";
	}
	else
	{
		cout << s.top() << "\n";
		s.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string t;
	t = "";
	long long n;
	long long first_num;

	while (1)
	{
		while (t != "END")
		{
			cin >> t;

			if (t == "QUIT")
				return 0;

			v.push_back(t);
		}

		cin >> n;
		for (long long i = 0; i < n; i++)
		{
			cin >> first_num;
			s.push(first_num);
			solve();
			s = stack<long long>();
		}
		
		cout << "\n";
		v.clear();
		t = "";
	}
}