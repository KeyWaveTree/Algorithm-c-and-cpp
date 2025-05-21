#include<iostream>

using namespace std;

int main()
{
    int prize, n, money;
    cin>> prize>>n>>money;

    if(prize*n> money) cout<< prize*n - money;
    else cout<< 0;

    return 0;
}