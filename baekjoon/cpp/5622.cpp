#include<iostream>
#include<string>

using namespace std;

int main()
{
	string Number;
	cin >> Number;

	int SUM = 0;
	for (int i = 0; i < Number.size(); i++)
	{
		if (Number[i] == 'A' || Number[i] == 'B' || Number[i] == 'C')
			SUM = SUM + 3;
		else if (Number[i] == 'D' || Number[i] == 'E' || Number[i] == 'F')
			SUM = SUM + 4;
		else if (Number[i] == 'G' || Number[i] == 'H' || Number[i] == 'I')
			SUM = SUM + 5;
		else if (Number[i] == 'J' || Number[i] == 'K' || Number[i] == 'L')
			SUM = SUM + 6;
		else if (Number[i] == 'M' || Number[i] == 'N' || Number[i] == 'O')
			SUM = SUM + 7;
		else if (Number[i] == 'P' || Number[i] == 'Q' || Number[i] == 'R' || Number[i] == 'S')
			SUM = SUM + 8;
		else if (Number[i] == 'T' || Number[i] == 'U' || Number[i] == 'V')
			SUM = SUM + 9;
		else if (Number[i] == 'X' || Number[i] == 'Y' || Number[i] == 'Z' || Number[i] == 'W')
			SUM = SUM + 10;
	}
	cout << SUM << endl;
}