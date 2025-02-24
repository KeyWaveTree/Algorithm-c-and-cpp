#include<iostream>

using namespace std;

int main()
{
    int max = -1000001;
    int min = 1000001;
    int n;
    int i;
    int in;

    cin>> n;
    for(i=0;i<n;i++)
    {
        cin>>in;
        if(max<in) max=in;
        if(min>in)min=in;
    }

    cout<< min<<" "<<max;
    return 0;
}