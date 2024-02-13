// ���� �ڸ���
#include<iostream>

using namespace std;

char paper[1024][1024];
int T, N;

struct paperInfo 
{
	int redNumber = 0, redSize =0, blueNumber= 0, blueSize= 0;
};

paperInfo solution(int x, int y, int size)
{
	paperInfo result;

	// size 1�̸� red Ȥ�� blue ���� ó��
	if (size == 1)
	{
		if (paper[x][y] == 'R')
			result.redNumber = result.redSize = 1;
		else
			result.blueNumber = result.blueSize = 1;

		return result;
	}

	// 4��� �Ѵ� ( ����Լ� ) 
	paperInfo status[4];

	status[0] = solution(x, y, size / 2);
	status[1] = solution(x + size/2, y, size / 2);
	status[2] = solution(x, y + size / 2, size / 2);
	status[3] = solution(x + size / 2, y + size / 2, size / 2);

	for (int i = 0; i < 4; i++)
	{
		result.redNumber += status[i].redNumber;
		result.redSize += status[i].redSize;
		result.blueNumber += status[i].blueNumber;
		result.blueSize += status[i].blueSize;
	}

	if (result.redNumber == 0)
		result.blueNumber = 1;
	if (result.blueNumber == 0)
		result.redNumber = 1;

	return result;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> paper[i][j];
			}
		}

		paperInfo answer = solution(0, 0, N);

		cout << answer.redNumber << " " << answer.redSize << " " << answer.blueNumber << " " << answer.blueSize << "\n";
	}
}