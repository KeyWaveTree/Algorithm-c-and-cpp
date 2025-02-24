#include <iostream>
#include <string>

using namespace std;

//문자열을 이용하여 제곱한 수의 뒷자리를 입력수와 비교한다.
int main()
{
    int i, j, k; //반복 iterator 변수
    int n; //반복 크기 변수
    int squareNum; //자기복제수인지 확인해야하는 입력 변수
    bool flag;

    string square;//원본 입력값
    string powNumber;//제곱된 값의 문장


    cin >> n; //반복크기 입력

    for (i = 0; i < n; i++)
    {
        //숫자로 입력
        cin >> squareNum;

        //입력한 값이 자기복제수가 맞는지 아닌지 모르기 때문에 일단 자기복제수를 판단하는 flag를 true로
        flag = true;

        //입력한 숫자를 문자열로 치환
        square = to_string(squareNum); //자연수를 문자열로
        powNumber = to_string(squareNum * squareNum);//제곱한 자연수를 문자열로

        //k는 n을 제곱한 숫자의 1의 자리에서 부터 끝자리까지 가는 반복수 (index)
        k = powNumber.length()-1;
        //j는 자연수 n의 1의 자리에서 부터 끝자리까지 가는 반복수(index)
        for (j = square.length()-1; j>=0; j--, k--)
        {
            //자기 복제수는 맨 뒷자리에서 앞까지 반복한 square의 요소값과 같은 요소값이 있어야 함.
            //powNumber은 자연수 n을 곱한 제곱수를 문자열로 바꾼것임.
            //현재 입력한 값이 자기 복제수라면 square가 powNumber에 포함 되어있어야 함. 단 주의할 점은 뒤에서 부터 각각 1의자리씩 비교 해야 함.

            //코드
            //만약 현재 끝자리에서 부터 비교한 값이 하나라도 일치 하지 않으면
            if (square[j] != powNumber[k])
            {
                //자기 복제수가 아니라고 표시
                flag = false;
                break;
            }
        }
        //반복문이 if문을 건들지 않고 다 끝나다면 yes라고 출력
        if (flag) cout<< "YES"<<'\n';
        else cout<< "NO"<<'\n';
        //아니면 no
    }

    return 0;
}