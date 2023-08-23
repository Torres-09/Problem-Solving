#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct mineral
{
	int x;
	int y;
	int z;

	bool operator<(mineral m1)
	{
		return z < m1.z;
	}

};


bool compare(const mineral m1, const mineral m2)
{
	return m1.z < m2.z;
}



void solve()
{
	int n;
	cin >> n;

	vector<mineral> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
		arr[i].z = arr[i].x + arr[i].y;
	}

	
	sort(arr.begin(), arr.end());
	
	
	int inha= 0;
	int biryong = 0;


	while(!arr.empty())
	{
		inha = inha + arr.back().x;
		arr.pop_back();
		if (arr.empty())
			break;
		biryong = biryong + arr.back().y;
		arr.pop_back();
	}
	cout << inha - biryong << "\n";
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}