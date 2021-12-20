#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct member {
	int age;
	string name;
};

bool compare(const member& p1, const member& p2)
{
	if (p1.age == p2.age)
		return false;
	return p1.age < p2.age;
}

int main()
{
	int N;
	cin >> N;
	vector<member> members;
	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		members.push_back({ age,name });
	}

	stable_sort(members.begin(), members.end(),compare);
	

	for (int i = 0; i < N; i++)
	{
		cout << members[i].age << " " << members[i].name << "\n";
	}
	system("pause");
}