#include<iostream>

using namespace std;

int main() {
    bool check[30 + 1] = {false};
    int not2[2] = {0};
    int i;
    int number;


    for (i = 0; i < 28; i++) {
        cin >> number; //과제를 한 학생 입력
        check[number] = true; //과제한 학생의 index 번호를 true로
    }

    number = 0;//number를 과제제출 안한 학생의 수로 사용
    for (i = 1; i <= 30; i++) {
        //만약 지금 현재 i 번호가 false로 표기 되어 있다면 과제를 안한 2명 중 한 학생이므로 not2 배열에 순차적으로 저장
        if (!check[i]) not2[number++] = i;
    }

    //not2에 있는 2가지 값을 비교했을때 0번지가 더 크다면 1번지를 먼저 출력후 0번지를 출력
    if (not2[0] > not2[1]) cout << not2[1] << '\n' << not2[0];
    else cout << not2[0] << '\n' << not2[1];

    return 0;
}