#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string &A, string &B)
{
	if (A.length() == B.length())
	{
		return A < B;
	}
	return A.length() < B.length();
}

int main()
{
	int N;
	string sentense;
	
	cin >> N;

	string *sentenses = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> sentense;
		sentenses[i] = sentense;
	}

	sort(sentenses, sentenses + N,compare);
	
	sentense = "A";

	for (int i = 0; i < N; i++)
	{
		if (sentense == sentenses[i])
		{
			continue;
		}
		cout << sentenses[i] << "\n";
		sentense = sentenses[i];
	}
	system("pause");
}