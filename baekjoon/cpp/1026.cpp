#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int compare(int a,int b)
{
	return a>b;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(),compare);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = (sum + (A[i] * B[i]));
	}

	cout << sum << "\n";
	system("pause");
}