#include<iostream>

using namespace std;

int main()
{
    int h, m;
    int add;
    int time;

    cin>> h>> m;
    cin>> add;

    time = h * 60 + m + add;

    cout<< time/60 %24 << ' '<< time%60;

    return 0;
}