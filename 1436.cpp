#include<iostream>

using namespace std;

int main()
{
	int N;
	int result[10000];
	int index = 0;
	for (int i = 666; ; i++)
	{
		int sixth = 0;
		int temp = i;
		while (temp != 0)
		{
			if (temp % 10 == 6)
			{
				sixth++;
			}
			else
			{
				sixth = 0;
			}
			if (sixth >= 3)
			{
				result[index] = i;
				index++;
				break;
			}
			temp = temp / 10;
		}
		
		if (index == 10000)
			break;
	}

	cin >> N;
	cout << result[N-1] << endl;
	system("pause");
}

// 666 1666 2666 3666 4666 5666 6660 6661 6662 6663 6664 6665 6666 6667 6668 6669 7666 8666 9666 10666 11666 12666 13666 14666 15666
// 16660 16661 16662