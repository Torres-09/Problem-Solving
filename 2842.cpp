#include<bits/stdc++.h>
using namespace std;
int n;
char miro[51][51];
int tired[51][51];
vector<int> tired_score;
int houseCount = 0;
pair<int, int> startPoint;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

bool bfs(int low, int high)
{
	queue<pair<int, int>> q;
	bool Visit[51][51];
	int houseVisit = 0;
	memset(Visit, false, sizeof(Visit));

	if (tired[startPoint.first][startPoint.second] >= tired_score[low] && tired[startPoint.first][startPoint.second] <= tired_score[high])
	{
		q.push({ startPoint.first,startPoint.second });
		Visit[startPoint.first][startPoint.second] = true;
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
				continue;

			if (Visit[next_x][next_y] == false && tired[next_x][next_y] >= tired_score[low] && tired[next_x][next_y] <= tired_score[high])
			{
				q.push({ next_x ,next_y });
				Visit[next_x][next_y] = true;

				if (miro[next_x][next_y] == 'K')
					houseVisit++;
			}
		}

		if (houseVisit == houseCount)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> miro[i][j];

			if (miro[i][j] == 'P')
				startPoint = { i,j };

			if (miro[i][j] == 'K')
				houseCount++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tired[i][j];
			tired_score.push_back(tired[i][j]);
		}
	}

	sort(tired_score.begin(), tired_score.end());
	tired_score.erase(unique(tired_score.begin(), tired_score.end()), tired_score.end());

	int low = 0;
	int high = 0;
	int result = INT_MAX;

	while (low < tired_score.size() && high < tired_score.size())
	{
		if (bfs(low, high))
		{
			result = min(result, tired_score[high] - tired_score[low]);
			low++;
		}
		else
		{
			high++;
		}
	}

	cout << result;
}