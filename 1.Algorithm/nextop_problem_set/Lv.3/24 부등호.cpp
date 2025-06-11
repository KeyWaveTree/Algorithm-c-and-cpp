#include<iostream>
#include<algorithm>

using namespace std;

char symbols[11];
bool check[10];
int number[10];
int n;
string ma = "0";
string mi = "9999999999";


void dfs(int index) {
    int i;
    string sum;
    //만약 지금 현재 모든 괄호의 답을 다 채웠다면 저장 후 return
    if (index == n) {
        for (i = n; i >= 0; i--) {
            sum += to_string(number[i]);
        }

        std::reverse(sum.begin(), sum.end());
        ma = (max(stoll(sum), stoll(ma)) == stoll(sum) ? sum : ma);
        mi = (min(stoll(sum), stoll(mi)) == stoll(sum) ? sum : mi);
        //cout << sum << '\n';
        return;
    }

    for (i = 0; i < 10; i++) {
        //만약 지금 표시할 수가 이미 사용한 숫자이거나 현재 숫자가 괄호방향에 맞지않는 수를 배치할려고 한다면 현재 반복을 건너뛴다.
        if (check[i] || (symbols[index] == '>' && number[index] < i) || (symbols[index] == '<' && number[index] > i))
            continue;
        number[index + 1] = i;
        check[i] = true;
        dfs(index + 1);
        check[i] = false;
    }

}

int main() {
    int index = 0;
    string symbol;

    cin >> n;
    cin.ignore();//남아 있는 입력 버퍼 제거

    getline(cin, symbol);

    for (auto i: symbol) {
        //만약 i값이 ' '이 아닐때만 symbol에다 넣어라
        if (i == ' ') continue;
        symbols[index] = i;
        index++;
    }

    for (index = 0; index < 10; index++) {

        number[0] = index;
        check[index] = true;
        dfs(0);
        check[index] = false;

    }
    cout << ma << '\n' << mi;
    return 0;
}