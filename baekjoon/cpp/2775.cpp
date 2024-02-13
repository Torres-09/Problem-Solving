#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int k, n;
		cin >> k >> n;	//���� ȣ��,
		int** apt = new int*[k+1];
		for (int i = 0; i < k+1; i++)
		{
			apt[i] = new int[n];
			memset(apt[i], 0, sizeof(int)*n);
		}

		for (int i = 0; i < n; i++)		//0 �� �ʱ�ȭ
		{
			apt[0][i] = i+1;
		}


		for (int i = 1; i < k+1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int y = j; y >= 0; y--)
				{
					apt[i][j] += apt[i - 1][y];
				}
			}
		}
				
		cout << apt[k][n-1] << endl;

		for (int i = 0; i < k; i++)
		{
			delete [] apt[i];
		}
		delete[] apt;
	}
}
