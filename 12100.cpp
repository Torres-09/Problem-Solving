#include<bits/stdc++.h>
using namespace std;
int n;
int answer;

// 최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
// 4^5 -> 2^10 -> 1024번 해보면 다 알 수 있음

vector<vector<int>> left(vector<vector<int>> board){
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (board[i][j] == 0)
				continue;

			for (int k = j - 1; k >= 0; k--) {
				if (board[i][k] == board[i][k + 1] && !check[i][k]) {
					board[i][k] *= 2;
					board[i][k + 1] = 0;
					check[i][k] = 1;
					break;
				}
				else if (board[i][k] == 0) {
					board[i][k] = board[i][k + 1];
					board[i][k + 1] = 0;
				}
				else break;
			}
		}
	}

	return board;
}

vector<vector<int>> right(vector<vector<int>> board) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = n - 2; j >= 0; j--) {
			if (board[i][j] == 0)
				continue;


			for (int k = j + 1; k < n; k++) {
				if (board[i][k] == board[i][k - 1] && !check[i][k]) {
					board[i][k] *= 2;
					board[i][k - 1] = 0;
					check[i][k] = 1;
					break;
				}
				else if (board[i][k] == 0) {
					board[i][k] = board[i][k - 1];
					board[i][k - 1] = 0;
				}
				else
					break;
			}
		}
	}

	return board;
}

vector<vector<int>> up(vector<vector<int>> board) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (board[j][i] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[k][i] == board[k + 1][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[k + 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[k + 1][i];
					board[k + 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

vector<vector<int>> down(vector<vector<int>> board) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if (board[j][i] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (board[k][i] == board[k - 1][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[k - 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[k - 1][i];
					board[k - 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return board;
}

void dfs(int cnt, vector<vector<int>> graph) {
	if (cnt == 5)
	{
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp = max(temp, graph[i][j]);
			}
		}

		answer = max(temp, answer);
		return;
	}

	dfs(cnt + 1, left(graph));
	dfs(cnt + 1, right(graph));
	dfs(cnt + 1, up(graph));
	dfs(cnt + 1, down(graph));

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, board);
	cout << answer;
}