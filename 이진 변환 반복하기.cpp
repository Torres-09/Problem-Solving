#include<bits/stdc++.h>

using namespace std;

string binary_conversion(int n) { // 10진수를 2진수로 변환하는 함수
    string result = "";
    while (n > 0) {
        result += to_string(n % 2);
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    int count = 0; // 이진 변환 횟수
    int total = 0; // 제거한 0의 개수
    while (s != "1") {
        int removed_zeros = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') removed_zeros++;
        }
        int length = s.length() - removed_zeros;
        s = binary_conversion(length); // 2진수로 변환
        count++;
        total += removed_zeros;
    }
    return { count, total };
}
