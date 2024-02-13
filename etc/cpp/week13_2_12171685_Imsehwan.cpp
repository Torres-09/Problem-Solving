// set
#include<iostream>
#include<set>

using namespace std;

int T, N, M;
int Messenger[500000];
int Answer[500000];

int main() {
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> Messenger[i];
		}

		set<int> Reader;

		for (int i = M - 1; i >= 0; i--)
		{
			if (Reader.find(Messenger[i]) == Reader.end())
			{
				Reader.insert(Messenger[i]);
			}

			Answer[i] = N - Reader.size();
		}

		for (int i = 0; i < M; i++)
		{
			cout << Answer[i] << "\n";
		}
	}

	return 0;
}