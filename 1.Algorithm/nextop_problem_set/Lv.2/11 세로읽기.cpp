#include<iostream>

using namespace std;

char arr[5][15+1]={'\0'};

int main()
{
    int i, j;
    for(i=0;i<5;i++)
    {
        cin>> arr[i];
    }

    for(i=0;i<15;i++)
    {
        for(j=0;j<5;j++)
        {
            if(arr[j][i] == '\0') continue;
            cout<< arr[j][i];
        }
    }
    return 0;
}