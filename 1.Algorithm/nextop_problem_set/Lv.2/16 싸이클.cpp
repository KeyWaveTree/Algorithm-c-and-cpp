#include<iostream>

using namespace std;

int main()
{
    int cycle[1001]= { 0 };
    int n, p, nn;
    int i;
    int cnt=0;
    cin >> n >> p;
    cycle[n]++;
    nn = n;
    while(true)
    {
        nn = nn * n % p;
        if(cycle[nn] == 2) break;

        cycle[nn]++;
    }

    for(i=0;i<=1000;i++)
    {
        if(cycle[i] == 2) cnt++;
    }

    cout<< cnt;
    return 0;
}