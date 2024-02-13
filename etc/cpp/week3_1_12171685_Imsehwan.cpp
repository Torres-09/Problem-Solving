#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node
{
	int parent = 0;
	vector<int> children;
	int length = 0;
};

int t, n, x, y;




void treetreave(int i, int directory[], node tree[])
{
	if (i == 1)
		directory[i] = 4;
	else
		directory[i] = directory[tree[i].parent] + 1 + tree[i].length;

	for (int j = 0; j < tree[i].children.size(); j++)
		treetreave(tree[i].children[j], directory, tree);

}

void solve()
{
	cin >> n;
	int *directory = new int[n+1];
	node *tree = new node[n+1];
	for(int i =0;i<n+1;i++)
	{
		directory[i] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		tree[x].children.push_back(y);
		tree[y].parent = x;
	}

	string s;
	cin >> s;
	tree[1].length = s.size();

	for (int i = 2; i < n+1; i++)
	{
		cin >> s;
		tree[i].length = s.size();
	}

	treetreave(1, directory, tree);

	for (int i = 1; i < n+1; i++)
		cout << directory[i] << "\n";
}



int main()
{
	
	cin >> t;
	while(t--){
		solve();
	}
}