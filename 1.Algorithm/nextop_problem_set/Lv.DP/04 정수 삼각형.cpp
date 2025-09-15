#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> itemTable;
int dpTable[500];

int main() {
    int i, j;
    int n, item;

    cin >> n;
    itemTable.resize(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            cin >> item;
            itemTable[i].push_back(item);
            if (i == n - 1) dpTable[j] = item;
        }
    }

    for (i = n - 2; i >= 0; i--) {
        int *temp = new int[i + 1];
        for (j = 0; j <= i; j++) {
            temp[j] = max(itemTable[i][j] + dpTable[j], itemTable[i][j] + dpTable[j + 1]);
        }
        for (j = 0; j <= i; j++) {
            dpTable[j] = temp[j];
        }

        delete[] temp;
    }
    cout << dpTable[0];

    return 0;
}