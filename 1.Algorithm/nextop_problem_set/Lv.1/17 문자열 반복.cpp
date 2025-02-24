#include<iostream>
#include<string>
using namespace std;

int main()
{
    short i, j, k;
    short n;
    short r;
    string s;

    cin>> n;

    for(i=0;i<n;i++)
    {
        cin>>r>>s;
        for(j=0;j<s.length();j++)
        {
            for(k=0;k<r;k++)
            {
                cout<<s[j];
            }
        }
        cout << '\n';
    }

    return 0;
}