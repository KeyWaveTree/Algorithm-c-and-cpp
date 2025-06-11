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
    //���� ���� ���� ��� ��ȣ�� ���� �� ä���ٸ� ���� �� return
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
        //���� ���� ǥ���� ���� �̹� ����� �����̰ų� ���� ���ڰ� ��ȣ���⿡ �����ʴ� ���� ��ġ�ҷ��� �Ѵٸ� ���� �ݺ��� �ǳʶڴ�.
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
    cin.ignore();//���� �ִ� �Է� ���� ����

    getline(cin, symbol);

    for (auto i: symbol) {
        //���� i���� ' '�� �ƴҶ��� symbol���� �־��
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