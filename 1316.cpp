#include<iostream>
#include<string>

using namespace std;

bool not_group_word(string &ABC)
{
	int result = true;	//group_word
	for (int i = 0; i < ABC.size(); i++)
	{
		for (int j = 1; j < ABC.size(); j++)
		{
			if (i!=j) {
				if (ABC[i] == ABC[j])
				{
					if (j - i != 1) {
						result = false;
						return result;
					}
					i = j;
				}
			}
		}
	}
	return result;
}

int main()
{
	int T;
	cin >> T;
	int sum =0;	//단어의 개수
	while (T--)
	{
		string sentence;
		cin >> sentence;
		if (not_group_word(sentence) == true)
			sum++;
	}
	cout << sum << endl;
}