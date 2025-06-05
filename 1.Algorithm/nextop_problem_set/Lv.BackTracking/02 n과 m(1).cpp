#include<iostream>

using namespace std;

bool check[8 + 1];
int arr[8];

void combination(int n, int m, int index) {
    int i;
    if (m == 0) {
        for (i = 0; i < index; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (i = 1; i <= n; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[index] = i;
        combination(n, m - 1, index + 1);
        arr[index] = 0;
        check[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    combination(n, m, 0);
}