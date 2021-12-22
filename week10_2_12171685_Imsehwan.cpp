 //Longest Increasing Subsequece Problem *최장 증가 부분 수열 문제
 //Dynamic Programming 동적 프로그래밍 활용
#include <iostream>
#include <algorithm>
using namespace std;

int T, N, Ans;
int Matryoshka[501];
int DP[501];

int main() {

	cin >> T;

	while (T--) {

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> Matryoshka[i];
		}
		Ans = 0;

		for (int i = 1; i <= N; i++)
		{
			DP[i] = 1;

			for (int j = 1; j < i; j++)
			{
				if (Matryoshka[j] < Matryoshka[i])
				{
					DP[i] = max(DP[i], DP[j] + 1);
				}
			}
			Ans = max(DP[i], Ans);
		}

		cout << Ans << "\n";
	}

	return 0;
}