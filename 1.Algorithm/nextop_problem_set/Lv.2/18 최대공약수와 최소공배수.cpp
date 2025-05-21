#include<iostream>

using namespace std;

int main()
{
    int n, m;
    int nn, mm;
    int temp;
    cin>> n>>m;

    nn = n, mm = m;
    //둘 중 하나가 0이 될때까지 반복하라.
    while(n*m !=0)
    {
        //만약 나누는 대상 보다 나누는 값이 더 크다면 서로 바꾼다.
        if(n < m)
        {
            temp = n;
            n = m;
            m = temp;
        }
        n%=m;
    }
    cout<< n+m<<'\n';
    cout<< (nn*mm)/(n+m);

    return 0;
}