#include<iostream>

using namespace std;

int main()
{
    int n;
    int i;
    int sum=0;
    for(i=0;i<5;i++)
    {
        cin>> n;
        sum+=(n*n);
    }
    cout<< sum%10;

    return 0;
}