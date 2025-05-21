#include<iostream>

using namespace std;

int main()
{
    int a, b;
    int sum =0;
    int i, j;
    int cnt=0;

    cin>> a>>b;

    for(i=1;i<=1000; i++)
    {

        for(j=1;j<=i;j++)
        {
            cnt++;
            if(cnt>=a && cnt <=b) sum+=i;

        }
    }

    cout<< sum;

    return 0;

}