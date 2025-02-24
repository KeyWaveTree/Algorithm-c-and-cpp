#include<iostream>

using namespace std;

int main()
{
    int check[42]={0}; // n과 42로 나눈 나머지 중 나온 나머지를 저장할 수 있는 배열
    int n; //42로 나눈 나머지의 대상
    int i;
    int cnt=0;//나머지가 다른 숫자의 개수


    //입력이 10개이므로 10번 반뽁
    for(i=0;i<10;i++)
    {
        //입력
        cin>> n;
        //핵심 코드://42로 나눈 나머지는 0~41까지이므로 배열 인덱스와 매칭된 요소를 증가
        //목표는 입력한 값중에 서로 다른 나머지의 개수를 찾는 것이다.
        //42로 나눈 나머지는 반드시 0~41까지 숫자와 매칭된다.
        //나눈 나머지를 배열의 인덱스로 활용해서 인덱스가 나온 요소값을 증가시킨다면 그 인덱스는 나눈 나머지의 숫자이고
        //나머지가 다를때마다 다른 인덱스 위치에서 값을증가 할 것이다. 이에 따라서 다른 위치에 증가 된 나머지의 개수를 새면 되는것이다.
        check[n%42]++;
    }

    //0~41까지 반복하면서 요소값이 0이아닌 양수의 개수만 센다면 그것은 서로다른 나머지의 개수ㄹㄹ 세는 것과 같음.
    for(i=0;i<42;i++)//i가 0에서 42전까지 한칸씩 증가하면서 반복한다.
    {
        //반복한 값과 같은 인덱스 위치가 0이 아니라 자연수라면 cnt 변수의 값을 증가한다.
        if(check[i]>0) cnt++;
    }

    //다른 나머지의 개수를 샌 변수값을 출력하고 종료한다.
    cout<< cnt;
    return 0;
}