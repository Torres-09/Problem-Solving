#include<iostream>
#include<string>

using namespace std;

int main()
{
	while (1)
	{
		string arr;
		getline(cin, arr);
		if (cin.eof() == true)
			break;
		else
			cout << arr << "\n";
	}
}