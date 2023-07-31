#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;
int n;
vector<int> v;
int arr1[100001];
// 숫자, index
map<int,int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // 배열 개수 입력
    cin >> n;
    v.push_back(INT_MIN);
    // 첫 번째 배열 입력
    for(int i =0;i<n;i++) cin >> arr1[i];
    // 두 번째 배열 입력
    for(int i =0;i<n;i++){
        int num;
        cin >> num;
        m[num] = i;
    }

    // 배열에서 n 번째 원소까지 탐색
    for(int i =0;i<n;i++){
        // 순서가 뒤에 나온다면
        if(m[arr1[i]] > v.back()){
            // LCS 연장
            v.push_back(m[arr1[i]]);
            // 순서가 앞에 나온다면
        }else{
            // LCS 다시 앞에부터
            auto it = lower_bound(v.begin(),v.end(), m[arr1[i]]);
            *it = m[arr1[i]];
        }
    }

    cout << v.size() - 1;
}