#include<iostream>

using namespace std;

int main()
{
    int arr[100];
    int n, m;
    int i, j, k;
    int max = 0;

    cin>> n>>m;
    for(i=0;i<n;i++)
    {
        cin>> arr[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(i == j || i == k || j == k) continue;
                else if(arr[i] + arr[j]+ arr[k] > m) continue;
                if(max< arr[i] + arr[j]+ arr[k]) max = arr[i] + arr[j]+ arr[k];

            }
        }
    }
    cout<< max;
    return 0;
}