#include<iostream>
#include<algorithm>
using namespace std;
int n;
int score[301];
int dp[301];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	dp[0] = score[0];
	dp[1] = score[0] + score[1];
	dp[2] = max(score[0] + score[2], score[1] + score[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i] + score[i - 1]);
	}

	cout << dp[n - 1] << "\n";

	
}