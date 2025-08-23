#include<iostream>

using namespace std;

int main() {
    int n, k;
    int temp;
    int arr[1001];

    bool flag;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        flag = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                flag = false;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag) break;
    }

    cout << arr[k - 1];
    return 0;
}