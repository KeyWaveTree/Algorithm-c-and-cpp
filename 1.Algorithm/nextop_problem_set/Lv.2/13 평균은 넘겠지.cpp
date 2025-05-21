#include<iostream>
#include<cstdio>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-invalid-specifier"
using namespace std;

int main()
{
    int student[1000];
    int c;
    int i, j;
    int n;
    int cnt;
    float sum, avg;

    cin>> c;
    for(i=0;i<c;i++)
    {
        cin >> n;
        sum = 0;
        cnt = 0;
        //입력 및 성적 더하기
        for(j=0;j<n;j++)
        {
            cin>> student[j];
            sum += (float)student[j];
        }
        //평균을 넘는 학생
        avg = sum / (float)n;
        for(j=0;j<n;j++)
        {
            if(avg < (float)student[j]) cnt++;
        }
        printf("%.3f%%\n", (float)cnt/(float)n*(float)100);
    }
    return 0;
}