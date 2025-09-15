#include<iostream>

using namespace std;

int main() {
    int esm[3] = {0}; //입력값
    int remind[3] = {15, 28, 19}; //년도의 제한 값

    int year = 1;
    int i;
    bool check;

    cin >> esm[0] >> esm[1] >> esm[2];

    while (true) {
        check = true; //지금 현재 년도가 일치하는지 일치 안하는지 모르기에 일단 가능하다 보고,
        // 확인시 한번이라도 일치하지 않으면 답으로 처리 않하기 위한 표시를 만든다.
        for (i = 0; i < 3; i++) {
            //범위값을 넘어가는 년도들을 다시 1로 바꿔야 하기에 각 년도마다 제한년도의 나머지값을 계산한다
            //단 나머지를 사용시 0~제한값-1로 바뀌여지기에 15, 28, 19가 올때는 0으로 바뀌기에 처리 할수 없다.
            //esm 년도도 각 범위를 나머지로 계산하면 esm 년도도 0으로 바뀌기에 처리할 수 있다.
            //지금 현재 년도를 esm의 년도로 바꿨을때값이 esm년도와 하나라도 일치하지 않는다면 현재 년도는 정답이 아님으로 false를 부여 한다.
            //false를 부여 할때 &(and bit 연산)의 특성을 사용하여 모두 일치해야 답이 나올있게 구성한다.
            if (year % remind[i] != esm[i] % remind[i]) check &= false;
        }

        if (check) break;//확인시 true값을 계속 가지고 있다면 esm 년도가 모두 일치된다는 것이므로 반복문을 종료한다.
        year++; //하나라도 일치하지 않으면 다음 년도가 답이 맞는지 아닌지 확인하기 위해 년도를 증가한다.
    }
    cout << year;// 답을 출력한다.
    return 0;
}