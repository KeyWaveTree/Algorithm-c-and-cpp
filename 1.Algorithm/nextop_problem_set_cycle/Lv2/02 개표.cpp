#include<iostream>

using namespace std;

int main() {
    int a = 0, b = 0;
    int n;
    string vote;

    cin >> n;
    cin >> vote;

    for (int i = 0; i < n; i++) {
        if (vote[i] == 'A') a++;
        else if (vote[i] == 'B') b++;
    }

    if (a > b) cout << 'A';
    else if (a < b) cout << 'B';
    else cout << "Tie";

    return 0;
}