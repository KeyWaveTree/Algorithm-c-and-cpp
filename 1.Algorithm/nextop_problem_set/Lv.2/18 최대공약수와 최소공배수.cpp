#include<iostream>

using namespace std;

int main()
{
    int n, m;
    int nn, mm;
    int temp;
    cin>> n>>m;

    nn = n, mm = m;
    //�� �� �ϳ��� 0�� �ɶ����� �ݺ��϶�.
    while(n*m !=0)
    {
        //���� ������ ��� ���� ������ ���� �� ũ�ٸ� ���� �ٲ۴�.
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