#include<bits/stdc++.h>
using namespace std;
int signUpUser;
int totalPrice;
vector<int> arr; // ���� ������
vector<vector<int>> us;
vector<int> ec;

void func(int size) {
	if (size == ec.size()) {
		// ������ ���
		int tempSignUp = 0;

		// �� ���űݾ�
		int tempTotalPrice = 0;

		// ��������
		for (auto v : us) {
			int buy = 0;
			int mustbuy = v[0];
			// �̸�Ƽ�� ����
			for (int i = 0; i < ec.size(); i++) {
				// ���� �̻��̸� �����Ѵ�.
				if (mustbuy <= arr[i])
					buy += ec[i] * arr[i] / 100;

				// �������� �̻��̸� ���񽺿� �����Ѵ�.
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

// �̸�Ƽ�� ���� 10, 20, 30, 40 �������� ���´�. �̸�Ƽ�� 7�� -> �ܼ��ϰ� �ϸ� 4^7 -> 2^14 -> �뷫 10000��
// ���� 100�� -> 10000 * 100 -> �鸸

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<vector<int>> users = { {40, 10000},{25, 10000} };
	vector<int> emoticons = { 7000, 9000 };
	solution(users, emoticons);
}