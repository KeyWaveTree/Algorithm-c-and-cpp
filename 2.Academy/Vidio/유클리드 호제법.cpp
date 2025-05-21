#include<iostream>

using namespace std;

int main()
{
    int a, b;
    int temp;
    cin>> a>>b;

    while(a*b!=0)
    {
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        a %= b;
    }

    cout << a+b;
}