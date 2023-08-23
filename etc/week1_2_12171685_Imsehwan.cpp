#include<iostream>
#include<stack>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	stack<int>block;
	stack<int>block_max;
	stack<int>block_min;

	while (n--)
	{

		int x, y;
		cin >> x;

		if (x == 1)
		{
			cin >> y;
			if (block.empty())
			{
				block_max.push(y);
				block_min.push(y);
			}
			else
			{
				if (block_max.top() <= y)
					block_max.push(y);
				else
					block_max.push(block_max.top());

				if (block_min.top() >= y)
					block_min.push(y);
				else
					block_min.push(block_min.top());
			}

			block.push(y);

			cout << block_min.top() << " " << block_max.top() << "\n";
		}
		else if (x == 2)
		{
			if (!block.empty())
			{
				block.pop();
				block_max.pop();
				block_min.pop();
			}
		}

		
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}