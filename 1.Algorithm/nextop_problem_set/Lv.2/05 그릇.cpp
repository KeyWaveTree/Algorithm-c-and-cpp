#include<iostream>

using namespace std;

int main()
{
    string line;
    char cur;
    int i;
    int sum=10;

    cin>> line;
    cur = line[0];
    for(i=1;i<line.length();i++)
    {
        if(cur == line[i]) sum+=5;
        else
        {
            sum+=10;
            cur = line[i];
        }
    }
    cout<< sum;

    return 0;
}