#include<iostream>

using namespace std;

int main()
{
    int student[100] = {0};
    int n;
    int in;
    int i;
    int temp;

    cin>> n;
    for(i=0;i<n;i++)
    {
        cin>>in;
        student[i] = i+1;
        for(int pre=i;pre>i-in;pre--)
        {
            temp = student[pre];
            student[pre] = student[pre-1];
            student[pre-1] = temp;
        }
    }

    for(i=0;i<n;i++)
    {
        cout<< student[i]<<' ';
    }
    return 0;
}
