#include<iostream>

using namespace std;

int main()
{
    int arr[100][100]={0};
    int x, y;
    int i, j;
    int cnt =0;
    int sw = 1;
    int n, m = 1;

    cin>>n;
    x = y = n/2+1;

    while(true)
    {

        for(j=1;j<=m;j++)
        {
            cnt++;
            arr[y][x] = cnt;
            y+=sw;
        }
        if(cnt>=n*n) break;

        for(i=1;i<=m;i++)
        {
            cnt++;
            arr[y][x] = cnt;
            x+=sw;
        }
        if(cnt>=n*n) break;
        m++;
        sw*=-1;
    }

    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
            cout<< arr[i][j]<<' ';
        }
        cout<< '\n';
    }
    return 0;
}