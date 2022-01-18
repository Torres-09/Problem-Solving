// 가운데를 말해요
// max_heap과 min_heap 사용
// 중간값 출력
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	cin >> n;
	int number;
	int count = 0;
	while (n--)
	{
		cin >> number;
		if (count == 0)
		{
			max_heap.push(number);
			count++;
		}
		else
		{
			min_heap.push(number);
			count--;
		}

		if(!min_heap.empty())
			if (max_heap.top() > min_heap.top())
			{
				int maxtop = max_heap.top();
				int mintop = min_heap.top();
				max_heap.pop(); min_heap.pop();
				max_heap.push(mintop); min_heap.push(maxtop);
			}
		
		cout << max_heap.top() << "\n";
	}

}