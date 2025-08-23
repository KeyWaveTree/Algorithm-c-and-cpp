#include<iostream>
#include<vector>

using namespace std;

vector<int> dpTable;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    int i;
    int start, end;
    int item = 0, sum = 0;

    cin >> n >> t;
    for (i = 0; i <= n; i++) {
        if (i != 0)cin >> item;
        sum += item;
        dpTable.push_back(sum);
    }

    for (i = 0; i < t; i++) {
        cin >> start >> end;
        cout << dpTable[end] - dpTable[start - 1] << '\n';
    }

    return 0;
}