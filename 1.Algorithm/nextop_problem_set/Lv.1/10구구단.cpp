#include<iostream>

using namespace std;

int main()
{
    short n;
    short i;
    cin>>n;

    for(i=1; i<10; i++)
    {
        cout<< n <<" * "<<i<<" = "<<n*i<<'\n';
    }

    return 0;
}