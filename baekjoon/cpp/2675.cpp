#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int R;
		int R_temp;
		cin >> R;
		R_temp = R;
		char* S = new char[21];
		cin >> S;
		for (int i = 0; i < strlen(S); i++)
		{
			while (R_temp--)
			{
				cout << S[i];
			}
			R_temp = R;
		}
		cout << endl;
	}
}