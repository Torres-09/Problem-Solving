#include<bits/stdc++.h>
using namespace std;
vector<int> v[2];
deque<int> dq;
bool Visit[1000001];
int temp;
int n;
int k;

int solution(int num1, int num2)
{
	int result = 0;
	for (int i = 0; i < dq.size(); i++)
	{
		if (i == num1)
			result = result * 10 + dq[num2];
		else if (i == num2)
			result = result * 10 + dq[num1];
		else
			result = result * 10 + dq[i];

		if (i == 0 && result == 0)
			return -1;
	}
	return result;
}

void solve()
{
	cin >> n >> k;
	if (n < 10)
	{
		cout << -1;
		return;
	}

	if (n < 100)
	{
		if (n % 10 == 0)
		{
			cout << -1;
			return;
		}
		
	}

	int t = 0;
	int not_t = 1;
	v[t].push_back(n);

	while (k--)
	{
		memset(Visit, false, sizeof(Visit));

		while (!v[t].empty())
		{
			dq = deque<int>();
			n = v[t].back();
			v[t].pop_back();

			int num;

			while (n != 0)
			{
				num = n % 10;
				dq.push_front(num);
				n /= 10;
			}
			for (int i = 0; i < dq.size(); i++)
			{
				for (int j = i + 1; j < dq.size(); j++)
				{
					temp = solution(i, j);
					if (!Visit[temp])
					{
						Visit[temp] = true;
						v[not_t].push_back(solution(i, j));
					}
				}
			}
		}

		if (n == -1)
		{
			cout << -1;
			return;
		}

		if (t == 0)
		{
			t = 1;
			not_t = 0;
		}
		else
		{
			t = 0;
			not_t = 1;
		}
	}

	sort(v[t].begin(), v[t].end());
	cout << v[t].back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}