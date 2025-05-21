#include <iostream>
#include<string>
using namespace std;

int main()
{
    string line;
    int i;

    while(true)
    {
        getline(cin,line);
        if(line == "END") break;
        for(i= line.length()-1; i>=0;i--)
        {
            cout << line[i];
        }
        cout<<'\n';
    }
    return 0;
}