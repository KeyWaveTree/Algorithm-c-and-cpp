#include<iostream>

using namespace std;

int main() {
    int bowl[100 + 1] = {0};
    int n, m;
    int i, j;
    int start, end, ball;

    cin >> n >> m;

    for (i = 0; i < m; i++) {
        cin >> start >> end >> ball;
        //start에서 부터 end까지 ball을 넣어라
        for (j = start; j <= end; j++) bowl[j] = ball;
    }

    for (i = 1; i <= n; i++) cout << bowl[i] << ' ';

    return 0;

}