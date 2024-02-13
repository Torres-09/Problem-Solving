#include<iostream>
#include<string>


using namespace std;

void solve()
{

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		for (int j = 0;; j = j + 2*K)
		{
			if (i + j >= S.length())
				break;
			else
				cout << S[j + i];

			if (j + 2 * K - i - 1 >= S.length())
				break;
			else
				cout << S[j + 2 * K - i - 1];
		}
	}
	cout << "\n";
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}