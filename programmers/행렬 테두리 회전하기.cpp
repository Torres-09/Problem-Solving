#include<bits/stdc++.h>

using namespace std;
int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	int index = 1;
	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < columns; j++) {
			arr[i][j] = index++;
		}
	}

	int x1, x2, y1, y2;
	for (auto query : queries) {
		vector<int> temp;
		x1 = query[0];
		y1 = query[1];
		x2 = query[2];
		y2 = query[3];

		for (int i = y1; i <= y2; i++)
			temp.push_back(arr[x1][i]);
		for (int i = x1; i <= x2; i++)
			temp.push_back(arr[i][y2]);
		for (int i = y2; i > y1; i--)
			temp.push_back(arr[x2][i]);
		for (int i = x2; i > x1; i--)
			temp.push_back(arr[i][y1]);

		answer.push_back(*min_element(temp.begin(), temp.end()));
		rotate(temp.begin(), temp.end() - 1, temp.end());

		index = 0;
		for (int i = y1; i <= y2; i++)
			arr[x1][i] = temp[index++];
		for (int i = x1; i <= x2; i++)
			arr[i][y2] = temp[index++];
		for (int i = y2; i > y1; i--)
			arr[x2][i] = temp[index++];
		for (int i = x2; i > x1; i--)
			arr[i][y1] = temp[index++];
	}
	
	return answer;
}