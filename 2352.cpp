#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
int n;
int arr[40001];
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    v.push_back(INT_MIN);
    for(int i=0;i<n;i++){
        cin >> arr[i];

        if(v.back() < arr[i]){
            v.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(v.begin(),v.end(),arr[i]);
            *it = arr[i];
        }
    }

    cout << v.size() - 1;
}