// ���� �ܾ� �����
//Naive algorithm
 //Dynamic Programming
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int score[24];

int needAlphabet[24][26];

int getScore[8388609];

int restAlphabet[8388609][26];

int M, answer;

string word;

void solution()
{
	getScore[0] = 0;

	for (int i = 1; i <= M; i++)
	{
		int status = 1 << (i - 1);

		for (int j = 0; j < status; j++)
		{
			bool flag = false;
			for (int k = 0; k < 26; k++)
			{
				if (restAlphabet[j][k] < needAlphabet[i][k])
					flag = true;
			}

			if (flag)
				continue;
			
			for (int k = 0; k < 26; k++)
			{
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			}

			getScore[j + status] = getScore[j] + score[i];
			answer = max(answer, getScore[j + status]);
		}
	}

}

int main()
{
	// ���ĺ� ���� �Է¹ޱ�
	for (int i = 0; i < 26; i++) 
	{
		cin >> restAlphabet[0][i];
	}

	// �ܾ� ���� �Է¹ޱ�
	cin >> M;

	// �ܾ�� ���� �Է¹ޱ�
	for (int i = 1; i <= M; i++)
	{
		cin >> word >> score[i];

		// �ܾ ���ĺ� ���� �����ϱ�
		for (int j = 0; j < word.size(); j++) 
		{
			needAlphabet[i][word[j] - 'a' ] += 1;
		}
	}

	solution();
	
	cout << answer<< "\n";
}