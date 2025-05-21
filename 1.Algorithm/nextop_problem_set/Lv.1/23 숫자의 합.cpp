#include<iostream>

using namespace std;

int main()
{
    int n;
    int i;
    int sum=0;
    string num;

    cin>> n;
    cin>> num;
    for(i=0;i<n;i++)
    {
        sum+= (int)num[i]-'0';
    }

    cout<< sum;

    return 0;
}