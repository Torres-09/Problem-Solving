#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int num1[100001];
// 숫자, 해당 숫자 num2에서의 index
map<int, int> secondMap;
// LCS의 길이, num1에서의 index 위치
vector<pair<int, int>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        secondMap[num] = i;
    }

    dp.assign(100001, {INT_MAX, -1});
    int result = 0;
    int index = 1;
    dp[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {

        // secondMap[num1[i]] -> 숫자가 가진 index 위치 LCS는 분명 1이 될거임

        // 두 번째 배열에서 등장하는 위치가 뒤에 있는 경우 (전보다 LCS가 1 길어진다.)
        if (secondMap[num1[i - 1]] < secondMap[num1[i]])
        {
            dp[index] = {dp[index - 1].first + 1, i};
        }
        // 두 번째 배열에서 등장하는 위치가 앞에 있는 경우 -> index 값을 찾아준다.
        else
        {
            sort(dp.begin(), dp.end());
            // LCS의 길이 = 1
            pair<int, int> cur = {1, i};
            auto a = lower_bound(dp.begin(), dp.end(), cur);

            if (a->first == INT_MAX)
            {
                cout << "hi";
            }
            else
            {
                a->first = cur.first;
                a->second = cur.second;
                index = a - dp.begin();
            }
        }

        result = max(result, dp[i].first);
    }

    for (int j = 0; j < n; j++)
    {
        cout << dp[j].first << " " << dp[j].second << "\n";
    }

    cout << result;
}

// 1. 데이터가 100000개라 이중 for문은 시간을 초과한다. -> 최소 N타임, NlogN타임이 필요하다 O
// 2. 기존과 다르게 숫자가 단 하나만 존재한다는 특성이 있다. -> 해당 숫자가 가질 수 있는 index는 단 하나뿐이다. -> Map을 사용? O
// 3. 만약 firstMap[i-1] < secondMap[i] 수열에 추가할 수 있다. 뒤에 있다면 새롭게 넣어주면 된다. LCS의 길이가 늘어날 것이다. O
// 4. 만약 새로운 문자열의 index가 기존 LCS의 위치보다 앞에 있다면???? lower_bound를 사용하여 해당 index보다 같거나 큰 위치에 해당 문자열을 삽입한다. O
// 5. 또한 index의 위치를 새롭게 가져온다. 오 그렇다면 총 N번만 비교연산하면 종료된다. O
// 6. lower_bound는 LCS의 길이가 계속 업데이트 ( 증가하는 방향으로 가기 때문에 사용가능하다.
// 7. lower_bound를 사용하기 위해서는 정렬되어 있어야 한다. pair에서 lower_bound를 사용하기 위해서는 first에 LCS의 길이값을, 두 번째에 index 값을 넣어준다.
// 8. 새로운 원소가 등장했을 때,,, LCS는 0이 될 것임. LCS가 0인 것 중에 index가 같거나 큰 곳에 삽입해준다.
// 9. sort할 때, first는 오름차순으로 index에 대하여 같거나 큰 곳이니까
// 10. index가 같은 경우는 절대 없다. 따라서 그것보다 최소 1이상 큰 위치로 iter를 반환하게 된다.
// 11. 해당 iter가 존재한다면? ->