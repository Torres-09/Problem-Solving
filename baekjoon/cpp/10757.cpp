#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string A;
	string B;
	cin >> A;
	cin >> B;
	if (A.size() > B.size())		// B가 무조건 크게 함
	{
		swap(A, B);
	}

	int B_index = B.size() - 1;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		B[B_index] += A[i];
		B_index--;
	}

	for (int i = B.size() - 1; i > 0; i--)
	{

		if (B[i] == 58)
		{
			B[i - 1] = B[i - 1] + 1;
			B[i] = 48;
		}
		else if (B[i] >= 96) {
			if (B[i] >= 106)
			{
				B[i - 1] = B[i - 1] + 1;
				B[i] = B[i] - 58;
			}
			else
			{
				B[i] = B[i] - 48;
			}
			}
		}
		if (B[0] == 58)
		{
			cout << "1";
			B[0] = 48;
		}
		else if (B[0] >= 96) {
		if (B[0] >= 106)
		{
			cout << "1";
			B[0] = B[0] - 58;
		}
		
		else
		{
			B[0] = B[0] - 48;
		}
	}


	cout << B << endl;
	system("pause");
}