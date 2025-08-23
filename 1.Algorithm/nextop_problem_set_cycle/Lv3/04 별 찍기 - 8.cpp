#include <iostream>

using namespace std;

int main() {
    int n;
    int p, q;
    int i, j;

    cin >> n;
    p = 0;
    q = n * 2;

    for (i = 1; i <= n * 2 - 1; i++) {
        //만약 반복수가 n줄을 초과한다면 별개수를 2 감소, 공백 2증가
        if (i > n) {
            p -= 2;
            q += 2;
        }
            //만약 반복수가 n줄 이하면 별개수를 2 증가, 공백 2감소
        else {
            p += 2;
            q -= 2;
        }
        //별개수를 반을 잘라 그 개수만큼 반복
        for (j = 1; j <= p / 2; j++) {
            cout << '*';
        }
        //공백의 개수 출력
        for (j = 1; j <= q; j++) {
            cout << ' ';
        }
        //별개수의 나머지 반을 출력
        for (j = 1; j <= p / 2; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}