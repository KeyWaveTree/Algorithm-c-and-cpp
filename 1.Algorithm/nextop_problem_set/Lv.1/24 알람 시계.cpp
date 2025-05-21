#include<iostream>

using namespace std;

int main()
{
    int h, m;
    int time;

    cin>> h>>m;

    time = (h*60) + m - 45;

    if(time < 0) cout<< 23 << ' ' << 60+(m-45);
    else cout<< (time/60)%24<< ' '<< time %60;

    return 0;
}