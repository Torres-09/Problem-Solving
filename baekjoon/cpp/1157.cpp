#include<iostream>
#include<string>

using namespace std;

int main()
{
	char* abc = new char[27];
	char* ABC= new char[27];
	int Abc[26] = { 0 };

	for (char i = 0; i < 26; i++)
	{
		abc[i] = 'a' + i;
		ABC[i] = 'A' + i;
	}
	abc[26] = '\0';
	ABC[26] = '\0';

	string Sentense;
	cin >> Sentense;

	for (int i = 0; i < Sentense.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (Sentense[i] == abc[j] || Sentense[i] == ABC[j])
			{
				Abc[j]++;
				break;
			}

		}
	}
	int Max=0;
	int Max_other = 0;
	int Index=0;

	for (int i = 0; i < 26; i++)
	{
		if (Max < Abc[i])
		{
			Max = Abc[i];
			Index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (Max == Abc[i])
		{
			Max_other++;
		}
	}

	if (Max_other > 1)
	{
		cout << "?" << endl;
	}
	else
		cout << ABC[Index] << endl;
}