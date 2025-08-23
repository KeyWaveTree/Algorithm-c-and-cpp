#include<iostream>

using namespace std;

int main() {
    int n;
    int a, b;
    int scoreA = 100, scoreB = 100;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a < b) scoreA -= b;
        if (a > b) scoreB -= a;
    }

    cout << scoreA << '\n' << scoreB;

    return 0;
}