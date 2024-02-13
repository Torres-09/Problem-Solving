#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;

        priority_queue<long,vector<long>,greater<long>> page;
        vector<long> dp(k+1,0);
        
        for(int i =0;i<k;i++){
            int num;
            cin >> num;
            page.push(num);
        }

        long a = page.top(); page.pop();
        long b = page.top(); page.pop();

        int index = 1;
        dp[0] = a + b;
        page.push(a+b);

        while(page.size() != 1){
            a = page.top(); page.pop();
            b = page.top(); page.pop();
            page.push(a+b);
            dp[index] = dp[index-1] + a + b;
            index++;
        }

        cout << dp[k-2] << "\n";
    }
}