#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long hanoi(long long a, long long b) {
    
}

int main() {
    long long n, m;
    cin >> n >> m;

    
    auto answer = (2 * m) *(hanoi(2, n + 1) - 1);
    if (answer < 0) answer += MOD;
    cout << answer;
}