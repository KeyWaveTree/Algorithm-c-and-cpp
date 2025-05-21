#include<iostream>

using namespace std;

int main()
{
    string n;
    while(!cin.eof())
    {
        getline(cin, n);
        cout<< n << '\n';
    }
    return 0;
}