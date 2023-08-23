#include<iostream>

using namespace std;

int main()
{
	int C;
	int N;
	cin >> C;
	while (C--)
	{
		cin >> N;
		int* arr;
		arr = new int[N];
		double ave = 0;
		double number = 0;//평균 넘는 학생 수
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			ave = ave +  arr[i];
		}
		ave = ave / N;
		for (int i = 0; i < N; i++)
		{
			if (ave < arr[i])
				number++;
		}
		cout << fixed; cout.precision(3);
		cout << (number / N) * 100 << "%"<<endl;
	}
}