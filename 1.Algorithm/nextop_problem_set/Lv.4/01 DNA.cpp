#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<string> dnaList; //해밍 거리를 구하기 위한 dna 나열들
    string subDnaChar = "ACGT";//dna 후보군
    string hammingDna = "";//후보군에서 만든 길이 m dna
    int n, m;
    int i, j, k;
    int cnt = 0;
    int sum = 0;//해밍 거리를 누적할 변수
    char cur = 'A';

    cin >> n >> m;

    //n개 요소를 받을 수 있도록 동적할당
    dnaList.assign(n, "");
    //5개의 문장을 먼저 입력받는다.
    for (i = 0; i < n; i++) {
        cin >> dnaList[i];
    }


    //입력받은 문장 5개 중 앞자리에서 부터 해밍거리가 짧은 문자를 고른다.
    //dna 후보군 중 알파벳 숫서대로 글자 하나를 고른다.
    //dna 나열들에서 맨 앞글자들과  dna 후보군에 고른 글자들을 순서대로 비교하며 가장 해밍거리가 작은 글자를 고른다.
    // -> 사실상 각 세로줄에서 가장 많이 나온 글자를 순서대로 이어 붙이는 문제이다.(각 세로줄에서 가장 자주 반복되는 글자를 하나씩 뽑아서 조합)
    // -> 다만 해밍거리가 같을때는 사전순으로 출력해야 한다는 것을 고려 해야 한다.

    //현재 dnalist의 세로줄 지정
    for (k = 0; k < m; k++) {
        int min = 1001;
        cur = 'A'; //문장에 넣을 알파벳 초기화

        //dna 후보군들 중 순서대로 글자 하나를 고른다.
        for (i = 0; i < 4; i++) {
            cnt = 0; //세로줄에 다른 글자가 몇개 있는지 세는 변수 초기화

            //dna리스트의 가로줄 지정
            for (j = 0; j < n; j++) {
                //지금 후보군과 dnaList의 세로줄 리스트가 같지 않다면
                if (subDnaChar[i] != dnaList[j][k]) cnt++;
            }

            //만약 후보군 글자기 지금 세로줄에 있는 글자들 비교시 가장 차이가 적게 발생한 값을 가지고 있는 글자라면
            if (cnt < min) {
                //최소치를 cnt로 바꾸고
                min = cnt;
                //문장에 넣을 알파벳을 i 위치 값으로 변경한다.
                cur = subDnaChar[i];
            }
        }

        //하나의 세로줄을 비교하면서 해밍거리가 가장 작은 수치를 가지는 값을 정답 문장에 넣는다. (혹은 출력한다.)
        hammingDna += cur;
        //현재 가장 작은 차이를 저장한 min을 sum 변수에다가 누적한다.
        sum += min;
    }

    cout << hammingDna << '\n';
    cout << sum;

    return 0;
}