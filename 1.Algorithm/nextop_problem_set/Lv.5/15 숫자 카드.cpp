#include<iostream>
#include<vector>

using namespace std;

int main() {
    int i;
    int prefix = 1;
    vector<int> fibonacci;
    string number;
    string token = ""; //분리된 숫자들을 저장할 문자열


    cin >> number;

    //만약 숫자카드 숫자의 길이가 2 미만이라면 숫자카드는 1자리라는 뜻이므로 늘여놓을 수 있는 카드 배열의 개수는 1개이므로 1출력 후 종료
    if (number.length() < 2) {
        cout << 1;
        return 0;
    }

    //숫자카드의 자리가 늘어나면 늘어날 수록 배치할 경우가 피보나치 규칙을 따른다. 따라서 피보나치 벡터의 크기를 길이 +1로 한다.
    fibonacci.assign(number.length() + 1, 1);

    //숫자 카드의 자리가 2이상일때 피보나치의 답을 미리 fibonacci 배열에 넣는다.
    //숫자카드가 1자리일때 늘어놓을 경우의 수는 1
    fibonacci[0] = fibonacci[1] = 1;
    for (i = 2; i <= number.length(); i++) fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];

    //문자열 숫자 맨뒤에 의미없는 문자를 넣는다. -> 마지막 토큰을 계산하기 위해서
    number += 'a';
    for (i = 0; i < number.length(); i++) {
        //만약 지금 위치가 '0'이면(이 말은 맨 앞에 숫자가 10, 20, 30 중에 하나일때 발생시킨다.)
        if (number[i] == '0') {
            token = "";//앞숫자는 의미 없으므로 토큰을 초기화 한다.
            continue; //아래 코드도 의미 없으므로 반복을 건너뛴다.
        }

        //만약 마지막 반복이 아닐때만 현재 자리를 token에다가 넣는다. 마지막 반복은 지금까지 저장한 토큰을 반영하기 위해서 하는것이기때문에 의미없는 글자를 반영할 필요가 없다.
        if (i < number.length() - 1)token += number[i];


        if (number[i] >= '4'//만약 지금 현재 자리수가 4이상이거나 또는
            //1자리 앞을 가도 문장 범위에 포함되면서 지금 현재 자리에서 뒤 숫자와 조합했을때 숫자 34보다 크면
            || (i + 1 < number.length() - 1 && (((int) number[i] - '0') * 10) + ((int) number[i + 1] - '0') > 34)
            //2자리 앞을 가도 문장 범위에 포함되면서 그러한 2자리 앞에 0이 들어간다면
            || (i + 2 < number.length() - 1 && number[i + 2] == '0')) {
            prefix *= fibonacci[token.length()]; //토큰의 길이로 배열의 배치할 경우의 수를 찾는다. 그러한 수를 곱한다.
            token = "";//토큰을 초기화 한다.
        }
    }


    //출력
    cout << prefix;

    return 0;
}