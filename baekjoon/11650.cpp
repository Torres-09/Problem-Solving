#include<iostream>
#include<algorithm>

using namespace std;

struct space {
	int x;
	int y;

	bool operator < (space &spaces)
	{
		if (this->x == spaces.x)
		{
			return this->y < spaces.y;
		}
		return this->x < spaces.x;
	}

};


int main()
{
	int N;
	cin >> N;
	space *spaces = new space[N];
	for (int i = 0; i < N; i++)
	{
		cin >> spaces[i].x;
		cin >> spaces[i].y;
	}
	
	sort(spaces, spaces + N);
	
	for (int i = 0; i < N; i++)
	{
		cout << spaces[i].x << " ";
		cout << spaces[i].y << "\n";
	}

	system("pause");
}