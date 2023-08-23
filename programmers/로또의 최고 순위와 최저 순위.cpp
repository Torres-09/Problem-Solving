#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int zeroCount = 0;
	unordered_map<int, int> um;
	um.insert({ 6,1 });
	um.insert({ 5,2 });
	um.insert({ 4,3 });
	um.insert({ 3,4 });
	um.insert({ 2,5 });
	um.insert({ 1,6 });
	um.insert({ 0,6 });

	for (auto i : lottos) {
		if (i == 0)
			zeroCount++;
	}

	int correct = 0;
	for (auto i : lottos) {
		for (auto j : win_nums) {
			if (i == j)
				correct++;
		}
	}

	answer.push_back(um.at(correct + zeroCount));
	answer.push_back(um.at(correct));
	if (correct == 0) {
		answer.push_back(7-zeroCount);
		answer.push_back(6);
	}
	else if (correct == 1) {
		answer.push_back(6 - zeroCount);
		answer.push_back(6);
	}
	else {
		
	}

	return answer;
}