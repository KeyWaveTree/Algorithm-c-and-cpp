#include<iostream>

using namespace std;

int main()
{
    short n;
    short i;

    string str;

    cin>> n;

    for(i=0;i<n;i++)
    {
        cin>> str;
        if(str.length() >= 6 && str.length() <= 9) cout << "yes"<<'\n';
        else cout<< "no"<<'\n';
    }

    return 0;
}