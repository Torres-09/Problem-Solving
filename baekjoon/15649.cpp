#include<iostream>
#include<vector>


using namespace std;

const int MAX = 9;
vector<int> number;
bool visited[MAX] = { false };
int N, M;

void solve(int n)
{
	if (n == 0)
	{
		for (int i = 0; i < M; i++)
		{
			cout << number[i] << " ";
		}
		cout << "\n";
		
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			number.push_back(i);
			visited[i] = true;
			solve(n - 1);
			number.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	solve(M);
	system("pause");
}