#include<iostream>

using namespace std;

int main()
{
    int a[10001];
    int acc[10001];
    int n, m;
    int sum;
    int cnt=0;
    short i, j;

    cin>> n>>m;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];

        //이전 답과 현재 답을 더해서 지금까지의 합을 넣는다.
        acc[i] = acc[i-1]+a[i];//이전 답과 현재 답을 더해서 지금까지의 합을 넣는다.
    }

    //모든 답이 나올 위치를 파악하여
    // 수열의 j위치(지금까지 더한 합) 요소값에서
    // 수열의 i위치(수열이 시작하는 위치) -1 요소값을 빼준다.

    for(i=1;i<=n;i++) //시작 위치 //0번지는 밖으로 나가는 경우
    {
        for(j=1;j<=n;j++)//끝 위치
        {
            sum = acc[j]- acc[i-1];
            if(sum == m) cnt++;
        }
    }
    cout<< cnt;

    return 0;
}