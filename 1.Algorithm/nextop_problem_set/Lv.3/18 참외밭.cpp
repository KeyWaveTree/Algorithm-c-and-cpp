#include<iostream>

using namespace std;

class info
{
public:
    int direct;
    int distance;
    info(): direct(0), distance(0){}
};

int main()
{
    info* filed =new info[6];//동적 할당

    int n;//참외 개수
    int i;//반복하는 수
    int x_i, y_i;//최대값을 저장하는 위치
    int max_x=0, max_y=0;//최대값을 저장하기 위한 값
    int small;
    cin>> n;//입력
    //입력 및 큰 사각형의 너비 높이
    for(i=0;i<6;i++)
    {
        cin>> filed[i].direct>> filed[i].distance;
        //만약 방향이 1, 2이고 최대값보다 더 큰 숫자라면
        if((filed[i].direct == 1 || filed[i].direct==2) && max_x<filed[i].distance)
        {
            max_x= filed[i].distance;//x의 최대값을 현재 거리로 바꾸고
            x_i = i;//최대값 위치를 i번째 위치라고 변경
        }
        //만약 방향이 3, 4이고, 최대값보다 더 큰 숫자라면
        else if((filed[i].direct == 3 || filed[i].direct==4) && max_y<filed[i].distance)
        {
            max_y=filed[i].distance;//y의 최대값을 현재 거리로 바꾸거
            y_i = i;//최대값 위치를 i번재 위치라고 변경
        }
    }

    //현재 최대값 y위치 다음 위치가 x라면
    if((y_i+1)%6 == x_i)
    {
        //x의 위치에서 +2, +3을 한다.
        small = filed[(x_i+2)%6].distance * filed[(x_i+3)%6].distance;
    }
    //그게 아니면
    else
    {
        //y의 위치에서 +2, +3을 한다.
        small = filed[(y_i+2)%6].distance * filed[(y_i+3)%6].distance;
    }

    //큰사각형에서 작은 사각형을 뺀 넓이에서 참외의 개수를 곱한다.
    cout<< ((max_x * max_y) - small) * n;

    delete filed;//동적할당 해제

    return 0;
}
