// 연산자 끼워넣기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v[12];
int n;
int a, b, c, d;
vector<int> value;

void solve(int count, int q, int w, int e, int r, int result)
{
	if (q > a || w > b || e > c || r > d)
	{
		return;
	}

	if (count == n - 1)
	{
		value.push_back(result);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			solve(count + 1, q + 1, w, e, r, result + v[count + 1]);
		else if (i == 1)
			solve(count + 1, q, w + 1, e, r, result - v[count + 1]);
		else if (i == 2)
			solve(count + 1, q, w, e + 1, r, result * v[count + 1]);
		else if (i == 3)
			solve(count + 1, q, w, e, r + 1, result / v[count + 1]);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cin >> a >> b >> c >> d;

	solve(0, 0, 0, 0, 0, v[0]);
	sort(value.begin(), value.end());


	cout << value.back() << "\n" << value.front();
}