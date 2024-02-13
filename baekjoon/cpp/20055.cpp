#include <iostream>
using namespace std;

int arr[300];
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;

    int left = 1;
    int right = n * 2;

    for (int i = 1; i <= n * 2; i++)
    {
        cin >> arr[i];
    }
}