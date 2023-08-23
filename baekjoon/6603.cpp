#include <iostream>
using namespace std;
int arr[14];
int k;
int answer[14];

void combination(int start, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++)
    {
        answer[cnt] = arr[i];
        combination(i+1, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> k;
    while (k != 0)
    {
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        combination(0, 0);

        cout << "\n";
        cin >> k;
    }
}