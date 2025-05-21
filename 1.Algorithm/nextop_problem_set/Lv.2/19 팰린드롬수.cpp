#include<iostream>

using namespace std;

int main()
{
    int i;
    bool flag;
    string number;
    while(true)
    {
        cin>> number;
        flag = true;
        if(atoi(number.c_str()) == 0) break;
        for(i=0; i < number.length()/2; i++)
        {
            if(number[i] != number[number.length() - 1 - i])
            {
                flag =false;
                break;
            }
        }
        if(flag) cout<< "yes"<<'\n';
        else cout<< "no"<<'\n';

    }

    return 0;
}