// ¥‹æÓ∆€¡Ò
// KMP
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string puzzle[3000];
int N, M;
string row;
string col;
string cross;
vector <string> word;
int fail[50][3000];

void Failure() {
	for (int i = 0; i < word.size(); i++)
	{
		fail[i][0] = 0;
		int k = 0;
		int j = 1;
		while (j < word[i].size())
		{
			if (word[i][j] == word[i][k])
			{
				fail[i][j] = ++k;
				j++;
			}
			else if (k > 0)
			{
				k = fail[i][k - 1];
			}
			else
			{
				fail[i][j] = 0;
				j++;
			}
		}
	}
}

bool KMP(string pan, string w, int index)
{
	int i = 0;
	int j = 0;
	while (i < pan.size())
	{
		if (pan[i] == w[j]) 
		{
			if (j == w.size() - 1)
				return true;
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if (j > 0)
				j = fail[index][j - 1];
			else i++;
		}
	}
	return false;
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> puzzle[i];
	}

	for (int i = 0; i < M; i++)
	{
		string _word;
		cin >> _word;

		word.push_back(_word);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			row += puzzle[i][j];
		}
		row += "@";
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			col += puzzle[j][i];
		}
		col += "@";
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N - i; j++) 
		{
			cross += puzzle[j][i + j];
		}
		cross += "@";
	}

	for (int i = 1; i < N; i++) 
	{
		for (int j = 0; j < N - i; j++)
		{
			cross += puzzle[i + j][j];
		}
		cross += "@";
	}

	Failure();

	for (int i = 0; i < M; i++) 
	{
		bool fact;
		fact = KMP(row, word[i], i);
		if (!fact)
			fact = KMP(col, word[i], i);
		if (!fact)
			fact = KMP(cross, word[i], i);

		if (fact)
			cout << "1\n";
		else
			cout << "0\n";
	}
}
