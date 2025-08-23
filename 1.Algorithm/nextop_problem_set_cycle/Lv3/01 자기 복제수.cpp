#include<iostream>
#include<string>

using namespace std;
//문제제기 -> 점수를 어떻게 샐 것인가?

int main() {
    int t;
    int k, i, j;
    int num;
    bool flag;

    cin >> t;
    for (k = 0; k < t; k++) {
        cin >> num;
        flag = true;
        string n = to_string(num);
        string nn = to_string(num * num);

        for (i = n.length(), j = nn.length(); i >= 0; i--, j--) {
            if (n[i] != nn[j]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}