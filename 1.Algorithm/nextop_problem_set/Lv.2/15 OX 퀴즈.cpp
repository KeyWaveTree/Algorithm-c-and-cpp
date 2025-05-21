#include<iostream>

using namespace std;

int main()
{
    string ox;
    int n;
    int cnt, sum;
    int i, j;

    cin>> n;
    for(i=0;i<n;i++)
    {
        cin>> ox;
        cnt =0;
        sum =0;
        for(j=0;j<ox.length();j++)
        {
            if(ox[j] == 'O') cnt++;
            else  cnt =0;
            sum += cnt;
        }
        cout<< sum<<'\n';
    }

    return 0;
}