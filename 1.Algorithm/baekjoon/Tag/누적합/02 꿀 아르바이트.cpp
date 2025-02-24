#include<iostream>

using namespace std;

int value[100000];

//두가지 방법
//1. 처음부터 ni번지까지 합을 i번째 위치 메모이제이션(누적합) 후 처음 위치 이전 값 빼서 계산

//2. 슬라이딩 윈도우를 하여 누적합 계산
int main()
{
    int n, m;
    int i;
    long long max, sum=0;

    cin >> n >> m;

    for(i=1;i<=n;i++)
    {
        cin >> value[i];
        if(i <= m)
        {
            sum += value[i];
        }
    }

    max = sum;

    for(i=m+1;i<=n;i++)
    {
        sum+=value[i] -value[i-m];
        if(max< sum) max = sum;
    }

    cout << max;

    return 0;
}