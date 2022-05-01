#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int roomno[10] = { 0 };
	int num;
	cin >> num;

	if (num == 0)
	{
		cout << 1;
		return;
	}


	while (num > 0)
	{
		roomno[num % 10] += 1;
		num = num / 10;
	}

	int answer = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
			answer = max((roomno[6] + roomno[9])/2 + (roomno[6]+roomno[9]) % 2, answer);
		}
		else
			answer = max(roomno[i], answer);
	}

	cout << answer;
}

int main()
{
	solve();
}