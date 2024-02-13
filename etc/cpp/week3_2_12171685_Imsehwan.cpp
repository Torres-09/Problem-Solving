#include<algorithm>
#include<vector>
#include<iostream>


using namespace std;


struct roadinfo {
	int naver, distance;
};


int treesearch(int root, vector<roadinfo> *house, bool *visitedhouse, int &answer)
{
	int maxc = 0;
	int second = 0;
	int temp;

	visitedhouse[root] = true;
	for (int i = 0; i < house[root].size(); i++)
	{
		if (visitedhouse[house[root][i].naver] == false)
		{
			temp = treesearch(house[root][i].naver, house, visitedhouse, answer) + house[root][i].distance;

			if (temp > maxc)
				swap(temp, maxc);
			if (temp > second)
				swap(temp, second);
		}
	}

	answer = max(answer, maxc + second);

	return maxc;
}

void solve()
{
	vector<roadinfo> house[2001];
	bool visitedhouse[2001];
	for (int i = 0; i < 2001; i++)
	{
		visitedhouse[i] = false;
	}

	int n;
	cin >> n;
	

	int u, v, d;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v >> d;
		house[u].push_back({ v,d });
		house[v].push_back({ u,d });
	}

	int answer = 0;
	treesearch(1, house, visitedhouse, answer);
	
	cout << answer << "\n";
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}
}