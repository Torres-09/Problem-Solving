#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	while (1)
	{
		stack<char> sta;
		sta.push('1');
		bool flag = true;
		string arr;
		getline(cin, arr);

		if (arr == ".")
			return 0;

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == '(' || arr[i] == '[')
				sta.push(arr[i]);

			if (arr[i] == ')')
			{
				if (sta.top() == '(')
					sta.pop();
				else
				{
					cout << "no\n";
					flag = false;
					break;
				}
			}
			

			if (arr[i] == ']')
			{
				if (sta.top() == '[')
					sta.pop();
				else
				{
					cout << "no\n";
					flag = false;
					break;
				}
			}
			
		}

		if (sta.top()=='1' && flag == true)
			cout << "yes\n";
	}

}