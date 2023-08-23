#include<iostream>
#include<vector>

using namespace std;

int n, m, answer;
int*housearr;

bool check(int length);
int solution(int left,int right);
void solve();

int main()
{
	solve();
}

void solve()
{
	cin >> n >> m;
	housearr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> housearr[i];
	}
	answer = solution(1, housearr[n-1]);
	cout << answer << "\n";
}

bool check(int length)
{
	int house = 1;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (house <= housearr[i])
		{
			house = housearr[i] + length;
			count += 1;
		}

		if (count == m)
			return true;

	}
	return false;
}
int solution(int left, int right)
{
	int middle;

	if (left == right)
		return left;
	if (left + 1 == right)
		if (check(right) == true)
			return right;
		else
			return left;
	middle = (left + right) / 2;
	if (check(middle) == true)
		return solution(middle, right);
	else
		return solution(left, middle - 1);
}
