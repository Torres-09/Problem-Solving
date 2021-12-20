#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int X, Y;
		cin >> X >> Y;
		int distance = Y - X;	// 가야 하는 거리
		int result = 0;	//장치 작동 횟수

		for (int i = 1; i>0; i++)
		{
			if (distance - (2 * i) <= 0)
			{
				if (distance > i)
				{
					result = result + 2;
					break;
				}
				else if (distance <= i)
				{
					result = result + 1;
					break;
				}
			}
			distance = distance - (i * 2);
			result = result + 2;
		}
		cout << result << endl;
	}
}

//1 -> 1				1
//2 -> 1 1 대칭			2	O

//3 -> 1 1 1			3
//4 -> 1 2 1			3

//5 -> 1 2 1 1			4
// 6 - > 1 2 2 1 대칭	4	O

// 7 - > 1 2 2 1 1		5
// 8 -> 1 2 2 2 1		5
// 9 -> 1 2 3 2 1		5

// 10 - > 1 2 3 2 1 1	6
// 11 -> 1 2 3 2 2 1	6
// 12 -> 1 2 3 3 2 1	6	O

// 13 -> 1 2 3 3 2 1 1	7
// 14 -> 1 2 3 3 2 2 1	7
// 15 -> 1 2 3 3 3 2 1	7
// 16 -> 1 2 3 4 3 2 1	7

//17 -> 1 2 3 4 3 2 1 1 8
//18 -> 1 2 3 4 3 2 2 1 8
//19 -> 1 2 3 4 3 3 2 1 8
//20 -> 1 2 3 4 4 3 2 1	8	O
// 2 4 6 8 10

//2 4, (2) -> 1
//2 4 6,  (5) -> 2
//2 4 6, (2) -> 1
//2 4 6, (4) -> 1
//2 4, (5) -> 2

//아이디어 -> 2N을 계속 뺀다,(다음 2n보다 작게 남을 때 까지) -> 남는 수가 다음의 n보다 작거나 같으면 +1, n보다 크면 +2