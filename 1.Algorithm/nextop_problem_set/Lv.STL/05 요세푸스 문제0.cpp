#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> q;
    int k, n;
    int i;
    int item;
    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        q.push(i);
    }

    i = 0;
    cout << '<';
    while (!q.empty()) {
        item = q.front();
        q.pop();
        if (i + 1 == k) {
            cout << item;
            if (!q.empty()) {
                cout << ", ";
            }

        } else q.push(item);


        i = (i + 1) % k;
    }
    cout << '>';
    return 0;
}