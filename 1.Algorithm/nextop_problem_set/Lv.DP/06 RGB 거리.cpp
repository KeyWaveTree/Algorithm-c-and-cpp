#include<iostream>

using namespace std;

int main() {
    int n;
    int dp[3] = {0};
    int temp[3] = {0};
    int a, b, c;
    cin >> n;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 3; i++) {
            cin >> temp[i];
        }
        a = min(dp[1], dp[2]) + temp[0];
        b = min(dp[0], dp[2]) + temp[1];
        c = min(dp[0], dp[1]) + temp[2];

        dp[0] = a, dp[1] = b, dp[2] = c;
    }

    cout << min(dp[0], min(dp[1], dp[2]));

    return 0;
}