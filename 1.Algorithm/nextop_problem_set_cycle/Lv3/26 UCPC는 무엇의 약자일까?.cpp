#include<iostream>
#include<string>

using namespace std;

int main() {
    string n, ucpc = "UCPC";
    int i;
    int count = 0;

    //주어진 문장 받기 띄어쓰기 포함한 문장으로
    getline(cin, n);

    //입력문장 n에서 대문자 중 U, C, P, C가 부분 순서적으로 포함되어 있는지 없는지 확인
    for (i = 0; i < n.length(); i++) {
        //만약 n문장 요소가 U하고 일치되는 문자가 있다면 다음 단계로 넘어 간다.
        //만약 n문장 요소가 C하고 일치되는 문자가 있다면 다음 단계로 넘어 간다.
        //만약 n문장 요소가 P하고 일치되는 문자가 있다면 다음 단계로 넘어 간다.
        //만약 n문장 요소가 C하고 일치되는 문자가 있다면 다음 단계로 넘어 간다.
        //지금 다음 단계로 넘어간 횟수가 4번이 된다면 I love UCPC를 출력하고 프로그램을 종료한다.
        if (ucpc[count] == n[i]) count++;
        if (count == 4) {
            cout << "I love UCPC";
            return 0;
        }
    }

    //반복이 다끝나면 I hate UCPC를 출력하고 프로그램을 종료한다.
    cout << "I hate UCPC";
    //--------- 오답-------------
    //capital 변수에 UCPC가 포함되어있는지 확인하기
    //auto index = capital.find("UCPC");
    //(index == string::npos);index값이 현재 찾은 문자열이 존재하지 않는 경우 나타내는 값과 같다면
    //--------------------------


    return 0;
}