#include<iostream>

using namespace std;

int main() {
    int n;
    int p, q;
    int i, j;

    cin >> n;
    p = 2 * n + 1;
    q = -1;

    for (i = 1; i <= n * 2 - 1; i++) {
        if (i > n) {
            p += 2;
            q -= 1;
        } else {
            p -= 2;
            q += 1;
        }

        for (j = 1; j <= q; j++) {
            cout << ' ';
        }
        for (j = 1; j <= p; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}