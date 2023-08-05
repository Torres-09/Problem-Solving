#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long double n;

void solve(int num, int a, int b, int c)
{
    if (num == 1)
    {
        printf("%d %d\n", a, c);
    }
    else
    {
        solve(num - 1, a, c, b);
        printf("%d %d\n", a, c);
        solve(num - 1, b, a, c);
    }
}

int main()
{
    scanf("%Lf", &n);
    long double result = pow(2.0, n);
    char str[100001];
    sprintf(str, "%.0Lf", result);
    str[strlen(str) - 1] -= 1;
    if (n > 20)
    {
        printf("%s", str);
    }
    else
    {
        printf("%s\n", str);
        solve(n, 1, 2, 3);
    }
}
