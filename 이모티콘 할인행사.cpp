#include<bits/stdc++.h>
using namespace std;
int signUpUser;
int totalPrice;
vector<int> arr; // 각각 할인율
vector<vector<int>> us;
vector<int> ec;

void func(int size) {
	if (size == ec.size()) {
		// 가입한 사람
		int tempSignUp = 0;

		// 총 구매금액
		int tempTotalPrice = 0;

		// 유저마다
		for (auto v : us) {
			int buy = 0;
			int mustbuy = v[0];
			// 이모티콘 마다
			for (int i = 0; i < ec.size(); i++) {
				// 할인 이상이면 구매한다.
				if (mustbuy <= arr[i])
					buy += ec[i] * arr[i] / 100;

				// 일정가격 이상이면 서비스에 가입한다.
				if (buy >= v[1]) {
					tempSignUp++;
					buy = 0;
					break;
				}
			}
			tempTotalPrice += buy;
		}

		if (signUpUser <= tempSignUp) {
			if (signUpUser < tempSignUp)
				totalPrice = tempTotalPrice;
			else if (signUpUser == tempSignUp)
				totalPrice = max(totalPrice, tempTotalPrice);

			signUpUser = tempSignUp;
		}

		return;
	}


	for (int i = 10; i <= 40; i += 10) {
		arr.push_back(i);
		func(size + 1);
		arr.pop_back();
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	us = users;
	ec = emoticons;
	func(0);
	answer.push_back(signUpUser);
	answer.push_back(totalPrice);
	return answer;
}

// 이모티콘 마다 10, 20, 30, 40 할인율을 갖는다. 이모티콘 7개 -> 단순하게 하면 4^7 -> 2^14 -> 대략 10000개
// 유저 100명 -> 10000 * 100 -> 백만

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<vector<int>> users = { {40, 10000},{25, 10000} };
	vector<int> emoticons = { 7000, 9000 };
	solution(users, emoticons);
}