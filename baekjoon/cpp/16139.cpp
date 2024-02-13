#include <iostream>
#include <string>
using namespace std;
int cnt[26][200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    int q;
    cin >> q;

    cnt[s[0]-'a'][0]++;
    for(int i =1;i<s.size();i++){
        for(int j =0;j<26;j++){
            cnt[j][i] = cnt[j][i-1];
        }
        
        cnt[s[i] - 'a'][i] = cnt[s[i]-'a'][i-1] + 1;
        
    }

    for (int i = 0; i < q; i++)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;

        cout << cnt[c - 'a'][r] - (l == 0 ? 0 : cnt[c - 'a'][l - 1]) << "\n";
    }
}
