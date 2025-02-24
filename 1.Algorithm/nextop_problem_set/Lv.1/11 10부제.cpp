#include <iostream>

using namespace std;

int main()
{
    short n;
    short i;
    short num;
    short cnt=0;

    cin>>n;
    for(i=0;i<5;i++)
    {
        cin>>num;
        if(num%10 == n) cnt++;
    }

    cout<< cnt;
    return 0;
}