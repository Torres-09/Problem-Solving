#include<iostream>

using namespace std;

int main()
{
	char* ABC = new char[26];
	int abc[26] = { 0 };

	for (char i = 0; i < 26; i++)
	{
		ABC[i] = 'a' + i;
		abc[i] = -1;
	}

	char* S= new char[100];
	cin >> S;

	for (int i = 0; i < 100; i++)
	{
		if (S[i] == NULL)
			break;
		for (int j = 0;j<26; j++)
		{
			if (S[i] == ABC[j])
			{
				if (abc[j] == -1) {
					abc[j] = i;
					break;
				}
				else {
					break;
				}
			}
		}
	}

	for (int i = 0; i < 25; i++)
	{
		cout << abc[i] << " ";
	}
	cout << abc[25] << endl;
}