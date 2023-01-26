#include<bits/stdc++.h>
using namespace std;
string today;
vector<string> terms;

void Check(string privacy, vector<int> &answer, int order) {
	int year = stoi(privacy.substr(0, 4));
	int month = stoi(privacy.substr(5, 2));
	int day = stoi(privacy.substr(8, 2));
	map<char, int> mp;
	stringstream stream;
	
	for (string term : terms) {
		if (term[0] == privacy.back()) {
			month += stoi(term.substr(2));
		}
	}

	if (month > 12) {
		if (month % 12 == 0) {
			year += month / 12 - 1;
			month = 12;
		}
		else {
			year += month / 12;
			month %= 12;
		}
	}

	if (year < stoi(today.substr(0, 4))) {
		answer.push_back(order);
		return;
	}
	else if (year > stoi(today.substr(0, 4)))
		return;

	if (month < stoi(today.substr(5, 2))) {
		answer.push_back(order);
		return;
	}
	else if (month > stoi(today.substr(5, 2)))
		return;

	if (day <= stoi(today.substr(8, 2))) {
		answer.push_back(order);
		return;
	}

}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	::today = today;
	::terms = terms;
	int i = 1;
	for (string s : privacies) {
		Check(s, answer, i++);
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
}