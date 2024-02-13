#include<iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;

    int rem = 1000 - number;
    int Count = 0;
    Count += rem / 500;
    rem %= 500;
    Count += rem / 100;
    rem %= 100;
    Count += rem / 50;
    rem %= 50;
    Count += rem / 10;
    rem %= 10;
    Count += rem/5;
    rem %= 5;
    Count += rem;
    cout << Count;

}