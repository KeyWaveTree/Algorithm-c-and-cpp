#include<iostream>
#include<string>

using namespace std;

int main() {
    //피카츄가 발음할 수 있는 음절 모음.
    string pikachuVoice[3] = {"pi", "ka", "chu"};

    string s;

    int i, j, k, temp;
    bool flag = true;

    cin >> s;

    //입력 받은 문장 요소들을 반복한다.
    for (i = 0; i < s.length();) {
        temp = i;//현재 index값을 저장한다.

        //피카츄가 발음할 수 있는 음절 중에 입력 받은 부분 문자 중 하나가 일치하면
        //-> i 인덱스를 피카츄 음절 일치한 문장길이만큼 건너뛰기
        for (j = 0; j < 3; j++) {

            //피카츄 음절 일치 확인 반복문
            for (k = 0; k < pikachuVoice[j].length(); k++) {
                //현재 피카츄 음절과 입력받은 문자열 중 부분문자열을 1대 1대응 했을때 지금 글자가 일치하지 않는다면
                if (s[i + k] != pikachuVoice[j][k]) break; //반복을 종료
            }

            //만약 k값이 현재 피카츄 음절길이와 일치했다면 한번이라도 음절이 어긋난것이 없다는 뜻이므로 i값 수정
            if (k == pikachuVoice[j].length()) {
                //i값을 음절 길이 만큼 증가
                i += pikachuVoice[j].length();
                //j반복 종료
                break;
            }

        }

        //3번을 다하고 나서 인덱스가 바뀌지 않는다면 할수 없다는 표시를 넣은 후 break
        if (i == temp) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "YES";//만약 flag가 true라면 YES를 출력
    else cout << "NO";//아니라면 NO를 출력
    return 0;
}