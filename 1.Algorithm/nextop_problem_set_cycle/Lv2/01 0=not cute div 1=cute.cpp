#include<iostream>

using namespace std;

int main() {
    int n, i;
    int item;
    int score[2] = {0};

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> item;
        score[item]++;
    }

    if (score[0] < score[1]) {
        cout << "Junhee is cute!";
    } else {
        cout << "Junhee is not cute!";
    }

    return 0;
}