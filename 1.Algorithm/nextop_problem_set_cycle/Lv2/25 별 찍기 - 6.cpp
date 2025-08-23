#include<iostream>

using namespace std;

int main() {
    int n;
    int i, j;
    cin >> n;

    for (i = n; i >= 1; i--) {
        for (j = 1; j < n - i + 1; j++) {
            cout << ' ';
        }
        for (j = i * 2 - 1; j >= 1; j--) {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}