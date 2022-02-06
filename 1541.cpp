// ÀÒ¾î¹ö¸° °ıÈ£
#include<iostream>
#include<string.h>
using namespace std;
char arr[51];
bool minus_check = false;
int len, result;
int temp;

int main()
{
	cin >> arr;
	len = strlen(arr);

	for (int i = 0; i <= len; i++)
	{


		if (arr[i] == '-' || arr[i] == '+'||i==len)
		{
			if (minus_check == true)
			{
				result -= temp;
				temp = 0;
			}
			else
			{
				result += temp;
				temp = 0;
			}
		}
		else
		{
			temp *= 10;
			temp += arr[i] - '0';
		}

		if (arr[i] == '-')
			minus_check = true;
	}

	cout << result << "\n";
}