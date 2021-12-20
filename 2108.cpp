#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	vector<int> number;
	vector<int> countnum(8001, 0);

	double result1 = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		number.push_back(num);
		result1 += num;
		countnum[num + 4000]++;
	}
	sort(number.begin(), number.end());

	result1 = (result1 / N) + 0.5;

	int result2 = number[N / 2];

	int result3 = 0;
	
	int largest = countnum[0];
	
	for (int i = 1; i < 8001; i++)
	{
		largest = max(largest, countnum[i]);
	}
	int cnt = 0;
	int index = 0;

	for (int i = 0; i < 8001; i++)
	{
		if (countnum[i] == largest)
		{
			index = i;
			cnt++;
		}
		if (cnt == 2) {
			result3 = i -4000;
			break;
		}
		if (i == 8000)
		{
			result3 = index - 4000;
		}
	}
	
	int result4 = number[N - 1] - number[0];

	
	cout << floor(result1) << "\n" << result2 << "\n" << result3 << "\n" << result4 << "\n";
	
	system("pause");
}