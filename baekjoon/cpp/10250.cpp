#include<iostream>

using namespace std;

int main()
{
	int T, H, W, N;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		int* Hosu = new int[H*W];
		int NN = 0;
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j<H; j++)
			{
				Hosu[NN] = 100 * (j+1) + (i+1);
				NN++;
			}
		}
		cout << Hosu[N-1] << endl;
	}
}