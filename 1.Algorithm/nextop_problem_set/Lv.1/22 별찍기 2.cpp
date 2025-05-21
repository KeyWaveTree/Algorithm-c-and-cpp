#include<iostream>

using namespace std;

int main()
{
    int n;
    int i, j;
    cin >> n;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            cout<< ' ';
        }

        for(j=1;j<=i;j++)
        {
            cout<< "*";
        }
        cout<< '\n';
    }

    return 0;
}