#include<bits/stdc++.h>
using namespace std;
bool Visit[201][201][201];
vector<int> v;
int A, B, C;

void solve(int a,int b, int c)
{
	if (Visit[a][b][c]) return;

	Visit[a][b][c] = true;

	if (a == 0)
		v.push_back(c);
	
	// a 에서 b로
	if (a + b < B)
		solve(0, a + b, c);
	else
		solve(a + b - B, B, c);

	// a에서 c로
	if (a + c < C)
		solve(0, b, a + c);
	else
		solve(a + c - C, b, C);

	if (b + a < A)
		solve(a + b, 0, c);
	else
		solve(A, a+b-A, c);

	if (b + c < C)
		solve(a, 0, b+c);
	else
		solve(a, b + c - C, C);

	if (c + a < A)
		solve(a+c, b, 0);
	else
		solve(A, b, a + c - A);

	if (c + b < B)
		solve(a, b+c, 0);
	else
		solve(a, B, b + c - B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	solve(0,0,C);
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << " ";
}