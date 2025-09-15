#include<iostream>

using namespace std;

//왜 배열에 값을 하나하나씩 저장하고 출력하는 것보다 (4ms)
//입력하고 바로 출력하는 것이 더 느릴까? (260ms)
// -> i/o 작업의 오버헤드 및 버퍼링 현상
//c++ 에 cin/ cout은 기본적으로 서로 묶여 있음(tied)
// -> cin으로 입력받기 전에 cout 출력 버퍼에 남아 있는 내용이 있다면 강제로 비워 화면에 모두 출력
//
int main() {
    ios_base::sync_with_stdio(false); //stdio.h에 있는 scanf, printf의 동기화 비활성
    //cin과 cout의 묶음(동기화) 해제 그로인한 flash 현상 제거
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    int i;
    int item;

    cin >> n >> x;
    for (i = 0; i < n; i++) {
        cin >> item;
        //지금 입력한 item 값이 x값보다 작다면 출력
        if (item < x) {
            cout << item << ' ';
        }
    }

    return 0;
}