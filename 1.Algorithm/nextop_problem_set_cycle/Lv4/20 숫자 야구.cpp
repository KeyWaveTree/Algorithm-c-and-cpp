#include<iostream>
#include<vector>

using namespace std;

struct Info {
    string number;
    int strike;
    int ball;
};

//목표 모든 후보 숫자 중에 입력한 가능성과 정확히 일치하는 숫자의 개수를 구하는 것.

int main() {
    vector<Info> question;
    int n;
    int i, j, x, y;
    int strike, ball;
    string number, quest;
    int ansStrike, ansBall;
    bool isValid;
    int cnt = 0;

    cin >> n;
    question.assign(n, (Info) {"", 0, 0});

    //입력 질문 리스트
    for (i = 0; i < n; i++) {
        cin >> question[i].number >> question[i].strike >> question[i].ball;
    }

    //모든 경우의 수 숫자
    for (i = 123; i <= 987; i++) {
        number = to_string(i);

        //만약 숫자중 같은 숫자가 있다면 반복을 건너뛰어라
        //만약 숫자중 0인 숫자가 있다면 건너뛰어라
        if (number[0] == number[1] || number[1] == number[2] || number[0] == number[2]) continue;
        if (number[1] == '0' || number[2] == '0') continue;


        isValid = true; // 현재 i숫자가 최종 숫자 후보군이라고 가정
        //질문 리스트 개수 중 모든 질문 리스트의 결과와 맞는 숫자가 있다면 최종적인 숫자 후보군이다.
        //현재 i숫자가 n개의 질문지의 답과 비교해보며 스트라이트, 볼 개수가 맞는지 아닌지 확인하는 반복문
        //하나의 질문이라도 맞지 않는 i숫자는 후보에서 제외
        for (j = 0; j < n; j++) {
            strike = 0, ball = 0;
            //j번지 질문지의 질문을 가지고 온다.
            quest = question[j].number;
            ansStrike = question[j].strike;
            ansBall = question[j].ball;
            //질문지의 숫자와 i숫자가 스트라이크가 몇개인지 ball이 몇개인지 구한다.
            for (x = 0; x < 3; x++) { //i숫자의 각 자리
                for (y = 0; y < 3; y++) { //질문지 숫자의 각 3자리
                    //만약 같은 숫자가 있다면
                    if (quest[y] == number[x]) {
                        //스트라이크 일 경우 -> 각 숫자 자리가 일치할 경우
                        if (x == y) strike++;
                            //볼일경우
                        else ball++;
                    }
                }
            }

            //모든 경우의 수로 비교 하고 현재 숫자가 스트라이크와 볼 개수가 맞는지 아닌지 검사
            //만약 현재 구한 스트라이크 와 질문의 스트라이크와 일치하지 않다면 또는 현재 구한 볼과 질문의 볼과 일치 하지 않다면
            // -> 현재 수는 더이상 질문 리스트의 질문을 할 가치가 없으므로(가능성 숫자가 아니기 때문) 질문 반복 종료 후 최종 정답 후보에 반영 하지 않음.
            if (strike != ansStrike || ball != ansBall) {
                isValid = false; //최종 후보군 제외 표시
                break;
            }
        }

        //모든 질문을 다 통과시 최종 후보군 개수 증가
        if (isValid) cnt++;
    }
    cout << cnt;
    return 0;
}