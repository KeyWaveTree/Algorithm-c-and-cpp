#include<iostream>

using namespace std;

int main() {
    int t;
    int i, j, k;
    int item;

    cin >> t;

    for (i = 0; i < t; i++) {

        int arr[2] = {0};
        for (j = 0; j < 9; j++) {
            for (k = 0; k < 2; k++) {
                cin >> item;
                arr[k] += item;
            }
        }

        if (arr[0] > arr[1]) cout << "Yonsei" << '\n';
        else if (arr[0] < arr[1]) cout << "Korea" << '\n';
        else cout << "Draw" << '\n';

    }

    return 0;
}