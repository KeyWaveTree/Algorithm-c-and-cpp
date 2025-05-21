#include<iostream>

using namespace std;

int main()
{
    int i;
    int a, b, c,d;
    char ans[5+1]="DCBAE";
    for(i=1;i<=3;i++)
    {
        cin>> a>>b>>c>>d;
        cout<< ans[a+b+c+d]<<'\n';
    }

    return 0;
}
