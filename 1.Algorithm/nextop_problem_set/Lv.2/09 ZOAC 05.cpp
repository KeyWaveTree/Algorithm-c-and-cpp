#include<iostream>

using namespace std;

int main()
{
    string line;
    int i;
    int cnt = 0;
    char temp;

    cin >> line;
    temp = line[0];
    line = line + " ";

    for(i=0;i<line.length()-1;i++)
    {
        if(line[i] != temp) break;
        cnt++;
    }

    cout<< cnt;
    return 0;
}