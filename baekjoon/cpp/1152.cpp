#include<iostream>
#include<string>

using namespace std;

int main()
{
	string Sentense;
	getline(cin, Sentense);

	int size = 1;

	if (Sentense.size() == 1) {
		if (Sentense[0] == ' ') {
			cout << "0" << endl;
			return 0;
		}
	}
	else if (Sentense.size() > 0) {
		for (int i = 1; i < Sentense.size() - 1; i++)
		{
			if (Sentense[i] == ' ')
				size++;
		}
	}
	else
	{
		cout << "0" << endl;
		return 0;
	}
	cout << size << endl;
}