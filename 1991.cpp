#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[27];

void preorder(int start)
{
	if (start < 0 || start>26)
		return;

	cout << (char)(start + 65);

	for (int i = 0; i < graph[start].size(); i++)
	{
		preorder(graph[start][i]);
	}
}

void postorder(int start)
{
	if (start < 0 || start>26)
		return;

	for (int i = 0; i < graph[start].size(); i++)
	{
		postorder(graph[start][i]);
	}

	cout << (char)(start + 65);
}

void inorder(int start)
{
	if (start >= 0 && start<=26)
	{
		inorder(graph[start][0]);
		cout << (char)(start + 65);
		inorder(graph[start][1]);
	}
}

void solve()
{
	cin >> n;

	char root, left, right;
	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;

		graph[root - 65].push_back(left - 65);
		graph[root-65].push_back(right - 65);
	}

	preorder('A' - 65);
	cout << "\n";

	inorder('A' - 65);
	cout << "\n";

	postorder('A' - 65);
	cout << "\n";
}

int main()
{
	solve();
}