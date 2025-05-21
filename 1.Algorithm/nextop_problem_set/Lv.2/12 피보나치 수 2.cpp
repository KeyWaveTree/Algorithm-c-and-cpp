#include<iostream>

using namespace std;

int main()
{
    int n, i;
    long long fibo, cur=0, next=1;

    cin>> n;
    if(n<=1)
    {
        cout<< n;
        return 0;
    }

    for(i=2;i<=n;i++)
    {
        fibo = cur + next;
        cur = next;
        next = fibo;
    }

    cout<< fibo;
    return 0;
}