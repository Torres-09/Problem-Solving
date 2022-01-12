// 단지번호 붙이기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char house[26][26];
bool visit[26][26];
vector<int> sum;
int check;
int n;

void DFS(int row, int col)
{
	if (visit[row][col] == true)
		return;

	visit[row][col] = true;
	
	if(house[row][col]== '1')
	{
		check++;

		if (col != 0)
			DFS(row, col - 1);
		if (row != 0)
			DFS(row - 1, col);
		if (col != n - 1)
			DFS(row, col + 1);
		if (row != n - 1)
			DFS(row + 1, col);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> house[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check = 0;
			DFS(i, j);
			if(check!=0)
				sum.push_back(check);
		}
	}

	sort(sum.begin(), sum.end());
	cout << sum.size() << "\n";
	for (int i = 0; i < sum.size(); i++)
	{
		cout << sum[i] << "\n";
	}
}