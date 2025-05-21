#include<iostream>

using namespace std;

int main()
{
    int arr[10000];
    int n;
    int i, j;
    long long
    sum=0;

    cin>> n;
    for(i=0;i<n;i++)
    {
        cin>> arr[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum += abs(arr[i] - arr[j]);
        }
    }

    cout<< sum;
}